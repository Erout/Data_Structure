#include "huffman.hpp"
huffman::huffman(){
	root = NULL;
}
huffman::~huffman(){
	destroyTree(root);
}
void huffman::destroyTree(node* n){
	if(n == NULL)
		return;
	destroyTree(n->left_);
	destroyTree(n->right_);
	delete n;
}
void huffman::encodeGivenFrequency(){
	ifstream f1;
	f1.open("frequency.in");
	char c;
	double fre;
	//node* arr[56];
	memset(leaf,0,sizeof(leaf));
	int count = 0;
	while(!f1.eof()){
		f1>>c;
		f1>>fre;
		//cout<<c<<fre<<endl;
		if(c == '$' ){
			leaf[count] = new node(fre,' ');
			leaf[count]->special = "[space]";
		}
		else if(c == '!'){
			leaf[count] = new node(fre, '\n');
			leaf[count]->special = "[newLine]";
		}
		else{
			leaf[count] = new node(fre,c);
		}
		leaf[count]->len_ = 1;
		count++;
	}
	f1.close();
	setUpTree(leaf,count); 
	encodeFile();
}
void huffman::encodeFindFrequency(){
	ifstream fin;
	fin.open("mingwen.in");
	//node* leaf[56];
	memset(leaf,0,sizeof(leaf));
	int freq[130];
	memset(freq,0,sizeof(freq));
	char c;
	while((c = fin.get()) != EOF){
		freq[c]++;
	}
	int i = 0;
	int j = 10;
	char ch;
	node* temp;
	while(i < 56){
		if(j==10 || j==32 || j==44 || j==46 || (j >= 65 && j <= 90) || (j >= 97 && j <= 122)){
			ch = j;
			temp = new node(freq[j],ch);
			temp->len_ = 1;
			if(j == 10){
				temp->special = "[newLine]";
			}
			if(j == 32){
				temp->special = "[space]";
			}
			leaf[i++] = temp;
		}
		j++;
	}
	fin.close();
	setUpTree(leaf,i);
	encodeFile();
}
void huffman::setUpTree(node* arr[],int n){
	node* build = NULL;
	int count = n;
	int min1 = 0;
	int min2 = -1;
	while(count != 1){
		int min1 = 0;
		int min2 = -1;
		for(int i = 1; i < count; i++){
			if(arr[i]->weight_ < arr[min1]->weight_){
				if(min2 == -1){
					min2 = min1;
					min1 = i;
				}
				else if(arr[min1]->weight_ < arr[min2]->weight_){
					min2 = min1;
					min1 = i;
				}
				else{
					min1 = i;
				}
			}
			else if(min2 == -1){
				min2 = i;
			}
			else if(arr[i]->weight_ <arr[min2]->weight_){
				min2 = i;
			}
		}
		build = new node(arr[min1]->weight_ + arr[min2]->weight_);
		arr[min1]->parent_ = build;
		arr[min2]->parent_ = build;
		build->left_ = arr[min1];
		build->right_ = arr[min2];
		build->len_ = build->left_->len_ + build->right_->len_;
		arr[min1] = build;
		arr[min2] = arr[--count];		
	}
	root = build;
	traverseAddCode(root);
}
void huffman::traverseAddCode(node* n){
	if(n == NULL)
		return;
	if(n->left_ != NULL){
		n->left_->code_ = n->code_ + "0";
	}
	if(n->right_ != NULL){
		n->right_->code_ = n->code_ + "1";
	}
	if(n->left_ == NULL && n->right_ == NULL){
		//should be corrected
		M.insert(make_pair(n->code_,n->text_));
		code[n->text_] = n->code_;
	}
	traverseAddCode(n->left_);
	traverseAddCode(n->right_);
}
void huffman::encodeFile(){
	ifstream fin;
	ofstream fout;
	fin.open("mingwen.in",ios::in);
	fout.open("miwen.in",ios::out);
	if(!fin.good()){
		cout<<"fin not good";
		return;
	}
	if(!fout.good()){
		cout<<"fout not good";
		return;
	}
	char c;
	string tmp;
	double count = 0;
	double len = 0;
	while((c=fin.get() )!= EOF){
		//cout<<c;
		tmp = code[c];
		//cout<<code[c];
		count++;
		len += code[c].size();
		fout<<tmp;
	}
	//cout<<"len"<<len<<endl;
	//cout<<"count"<<count<<endl;
	yasuolv = len/(count*6);
	cout<<"压缩率: "<<yasuolv<<endl;
	fin.close();
	fout.close();
}
void huffman::decode(){
	ifstream fin;
	ofstream fout;
	fin.open("miwen.in");
	fout.open("mingwen2.in");
	string s;
	char c;
	while((c = fin.get()) != EOF){
		s += c;
		auto it = M.find(s);
		if(it != M.end()){
			fout<<(*it).second;
			s = "";
		}
	}
}
void huffman::printTree(node* n){
	if(n == NULL)
		return;
	for(int i = 0; i < n->len_; i++){
		if(n->special == "")
		 	cout<<n->text_;
		else
			cout<<n->special;
	}
	cout<<endl;
	printTree(n->left_);
	printTree(n->right_);
}
void huffman::showCodes(){
	cout<<"  字符"<<"   "<<"对应哈夫曼编码"<<endl;
	char c;
	//if(j==10 || j==32 || j==44 || j==46 || (j >= 65 && j <= 90) || (j >= 97 && j <= 122))
	c = 10;
	cout<<"  [newLine]"<<" "<<code[c]<<endl;
	c = 32;
	cout<<"  [space]"<<" "<<code[c]<<endl;
	c = 44;
	cout<<"  "<<c<<"     "<<code[c]<<endl;
	c = 46;
	cout<<"  "<<c<<"     "<<code[c]<<endl;
	for(int i = 65; i <= 90; i++){
		c = i;
		cout<<"  "<<c<<"     "<<code[c]<<endl;
	}
	for(int j = 97; j <=122; j++){
		c = j;
		cout<<"  "<<c<<"     "<<code[c]<<endl;
	}
}