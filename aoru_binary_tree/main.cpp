#include<iostream>
#include<string>
using namespace std;
struct node
{
	node* leftChild;
	node* rightChild;
	int dis;
	char text;
	node(char t){
		text = t;
		dis = 0;
	}
};
node* buildSubTree(string pre,string in);
void printTree(node* n);
int main(){
	string preorder,inorder;
	cin>>preorder>>inorder;
	node* root = buildSubTree(preorder,inorder);
	printTree(root);
} 
node* buildSubTree(string pre,string in){
	if(pre.empty()&&in.empty()){
		return NULL;
	}
	node* subRoot = new node(pre[0]);
	int i;
	for(i = 0; i < in.size(); i++){
		if(in[i] == pre[0])
			break;
	}
	int leftLen = i;
	string preLeft = pre.substr(1,leftLen);
	string preRight = pre.substr(leftLen+1,sizeof(pre)-leftLen-1);
	string inLeft = in.substr(0,i);
	string inRight = in.substr(leftLen+1,sizeof(in)-leftLen-1);
	subRoot->leftChild = buildSubTree(preLeft,inLeft);
	subRoot->rightChild = buildSubTree(preRight,inRight);
	if(subRoot->leftChild == NULL && subRoot->rightChild == NULL){
		subRoot->dis = 1;
	}
	else{
		subRoot->dis = 0;
		if(subRoot->leftChild != NULL){
			subRoot->dis += subRoot->leftChild->dis;
		}
		if(subRoot->rightChild != NULL){
			subRoot->dis += subRoot->rightChild->dis;
		}
	}
	return subRoot;
}
void printTree(node* n){
	if(n == NULL)
		return;
	for(int i = 0; i < n->dis; i++){
		cout<<n->text;
	}
	cout<<endl;
	printTree(n->leftChild);
	printTree(n->rightChild);
}