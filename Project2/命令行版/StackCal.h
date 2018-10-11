#include<iostream>
#include<stack>
#include<string>
using std::string;
using std::stack;
using std::cin;
using std::cout;
using std::endl;
class StackCal{
public:
	StackCal();
	~StackCal();
	void Input(string s);
	bool compute();
	void eraseOne();
	void clear();
	friend int stringToInt(string s);
	friend bool isNumber(char c);
	friend bool equalTo(char a,char b);
	friend bool smallerThan(char a,char b);
	friend double calculate(int front,int back, char operate);
private:
	string expression;
	stack<int> opNum;//储存操作数
	stack<char> opSign;//储存运算符
};