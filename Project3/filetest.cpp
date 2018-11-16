#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<map>
#define Size 100
using namespace std;
struct node
{
	node* left_;
	node* right_;
	node* parent_;
	double weight_;
	char text_;
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
class huff{
public:
	huff(){};
	~huff(){};
	void destroy(node* n){};
private:
	node* root;
	node* lead[56];
	map<string,char> M;
	string code[200];
};
int main(){
	huff obj;
	//system("pause");
}
