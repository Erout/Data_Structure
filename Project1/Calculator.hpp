#include<iostream>
#include<cstdio>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
struct single{
	single* next;
	double coefficient;
	int exponent;
	single(double c,int e){
		coefficient = c;
		exponent = e;
		next = NULL;
	}
};
class Calculator{
public:
	Calculator();
	~Calculator();
	bool Input(string s,int id);
	bool addItem(string s,int id);
	bool addItemToFirst(double coe,int exp);
	bool addItemToSecond(double coe,int exp);
	bool addItemToThird(double coe,int exp);
	void clearResult();
	void clear();
	bool add();
	bool subtract();
	bool multiple();
	void display();
	void showResult();
	void derivative(int id);
	void valueOfX(double x);
	void sort();
	friend int stringToInt(string s);
	friend double stringToDouble(string s);

private:
	single* first_head;
	single* second_head;
	single* result_head;
	int first_num;
	int second_num;
	int result_num;
};