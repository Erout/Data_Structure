#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
struct node
{
	node* left_;
	node* right_;
	node* parent_;
	double weight_;
	char text_;
	string special;
	string code_;
	int len_;
	node(double w,char t = '@'){
		text_ = t;
		left_ = NULL;
		right_ = NULL;
		parent_ = NULL;
		weight_ = w;
		len_ = 0;
	}
};
class huffman{
public:
	huffman();
	~huffman();
	void destroyTree(node* n);
	void setUpTree(node* arr[],int n);
	void encodeGivenFrequency();
	void encodeFindFrequency();
 	void traverseAddCode(node* n);
	void encodeFile();
	void decode();
	void printTree(node* n);
	node* getRoot(){
		return root;
	}
	void showCodes();
private:
	node* root;
	node* leaf[56];
	map<string, char> M;
	//index stands for ascii code for chars
	string code[130];
	double yasuolv;
};