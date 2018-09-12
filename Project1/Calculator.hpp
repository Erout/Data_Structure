#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
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
class Calculator{
public:
	static Calculator* getInstance();
	static bool deleteInstance();
	bool addItem(string s,int id);
	bool addItemToFirst(int coe,int exp);
	bool addItemToSecond(int coe,int exp);
	void clear();
	bool add();
	bool subtract();
	bool multiple();
	void display();
	void derivative(int id);
	void valueOfX(int x);
	friend int stringToInt(string s);

private:
	single* first_head;
	single* second_head;
	int first_num;
	int second_num;
	static Calculator* instance_;
	Calculator();
	~Calculator();
};