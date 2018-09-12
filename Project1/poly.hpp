#include<iostream>
#include<string>
#include<cmath>
using std::string;
using std::cin;
using std::cout;
using std::endl;
struct single{
	single* next;
	int coefficient;
	int exponent;
	single(int c,int e){
		coefficient = c;
		exponent = e;
		next = NULL;
	}
};
class Poly{
public:
	Poly();
	Poly(string s);//要确保是合法输入
	~Poly();
	friend int StringToInt(string s);
	void print();
	void AddPoly(string s);
	Poly* getNext();
	void setNext(Poly* p);
private:
	single* head;
	single* tail;
	Poly* next;
	int num;
};