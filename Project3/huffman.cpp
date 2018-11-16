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
	node* arr[56];
	memset(arr,0,sizeof(arr));
	int count = 0;
	while(!f1.eof()){
		f1>>c;
		f1>>fre;
		//cout<<c<<fre<<endl;
		arr[count] = new node(fre,c);
		arr[count]->len_ = 1;
		leaf[count] = arr[count];
		count++;
	}
	f1.close();
	setUpTree(arr,count); 
	encodeFile();
}
void huffman::encodeFindFrequency(){
	ifstream fin;
	fin.open("mingwen.in");
	node* arr[56];
	memset(arr,0,sizeof(arr));
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
			arr[i++] = temp;
		}
		j++;
	}
	fin.close();
	setUpTree(arr,i);
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
	printTree(root);
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
		//cout<<n->code_<<endl;
	}
	traverseAddCode(n->left_);
	traverseAddCode(n->right_);
}
void huffman::encodeFile(){
	ifstream fin;
	ofstream fout;
	fin.open("test.in",ios::in);
	fout.open("code.in",ios::out);
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
	while((c=fin.get() )!= EOF){
		//cout<<c;
		tmp = code[c];
		//cout<<code[c];
		fout<<tmp;
	}
	fin.close();
	fout.close();
}
void huffman::decode(){
	ifstream fin;
	ofstream fout;
	fin.open("decode.in");
	fout.open("decoder.in");
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
		cout<<n->text_;
	}
	printTree(n->left_);
	printTree(n->right_);
}
