#include "StackCal.h"
#include<cmath>
int stringToInt(string s){
	int total = 0;
	int sign;
	string ns;
	if(s[0] == '-'){
		sign = 1;
		ns = s.substr(1,s.size()-1);
	}
	else if(s[0] == '+'){
		sign = 0;
		ns = s.substr(1,s.size()-1);
	}
	else{
		sign = 0;
		ns = s;
	}
	for(int i = 0; i < ns.size(); i++){
		total += (ns[i]-'0')*pow(10,ns.size()-i-1);
	}
	if(sign == 0)
		return total;
	else
		return -total;
}
bool IsNumber(char c){
	if((c >='0')&&(c <= '9'))
		return true;
	return false;
}
bool equalTo(char a,char b){
	if((a == '(')&&(b == ')'))
		return true;
	if((a == '#')&&(b =='#'))
		return true;
	return false;
}
//判断符号a是否小于符号b,a不等于b
bool smallerThan(char a,char b){
	if(a == '#')
		return true;
	else if(a == ')')
		return false;
	else if(a == '('){
		if(b != '#')
			return true;
		else
			return false;
	}
	else if((a == '*')||(a == '/')){
		if((b == '(')||(b == '^'))
			return true;
		return false;
	}
	else if((a == '+')||(a == '-')){
		if((b == '*')||(b == '/')||(b == '(')||(b == '^'))
			return true;
		return false;
	}
	else if(a == '^'){
		if(b == '(')
			return true;
		return false;
	}
	return false;
} 
double calculate(int front,int back, char operate){
	double result;
	switch(operate){
		case '+':
			result = front+back;
			break;
		case '-':
			result = front-back;
			break;
		case '*':
			result = front*back;
			break;
		case '/':
			result = front/back;
			break;
		case '^':
			result = pow(front,back);
			break;
	}
	return result;
}
StackCal::StackCal(){
	opSign.push('#');
}
StackCal::~StackCal(){
	while(!opNum.empty())
		opNum.pop();
	while(!opSign.empty())
		opSign.pop();
}
void StackCal::Input(string s){
	expression = s;
	expression += '#';
}
void StackCal::eraseOne(){
	expression.pop_back();
}
void StackCal::clear(){
	while(!opNum.empty())
		opNum.pop();
	while(!opSign.empty())
		opSign.pop();
	expression = "";
	opSign.push('#');
}
/*有关负数： 参照电脑上的计算器的规则，乘除后可以使用负号，左括号后可以使用负号，将负号计入number中
加减号后不可以直接使用负号，也不可以++ -- 这样*/
bool StackCal::compute(){
	int pos = 0;
	int metSign = 0, metLeft = 0;//增加的
	string tempNum;
	int tempTop;
	char tempSign;
	int front,back;
	while(!opSign.empty()){
		//若取得的是符号,将之前的tempNum转化为数字，入栈
		//再对符号进行判断,先判断相等，再判断是否小于
		//取得的是符号
		if(!IsNumber(expression[pos])){
			//将tempNum push进去
			if(tempNum.size()){
				opNum.push(stringToInt(tempNum));
				tempNum.clear();//清空tempNum
			}
			//先处理几种特殊情况 ++ -- 负号之类
			//负号的情况
			if((metLeft == 1)&&((expression[pos]=='-')||(expression[pos] == '+'))){
				tempNum += expression[pos];
				pos++;
				metLeft = 0;
				continue;
			}
			//pop一个负号，pop一个数，减减加加之后再push进去
			if((metSign == 1)&&((expression[pos]=='-')||(expression[pos] == '+'))){
				//判断一下栈是否空，空则说明表达式非法，无法计算
				if(opNum.empty())
                    return false;
				opSign.pop();
				tempTop = opNum.top();
				opNum.pop();
				if(expression[pos] == '-')
					opNum.push(tempTop-1);
				else
					opNum.push(tempTop+1);
				pos++;
				metSign = 0;
				continue;
			}
			//相等
			if(equalTo(opSign.top(),expression[pos])){
				opSign.pop();
				pos++;
			}
			//若栈顶元素比读入的优先级低，则入栈 或者读到加号减号也先进去
			else if(smallerThan(opSign.top(),expression[pos])||((expression[pos] == '+')&&(expression[pos+1] == '+'))||((expression[pos] == '-')&&(expression[pos+1]=='-'))){
				opSign.push(expression[pos]);
				if(expression[pos] == '('){
					metLeft = 1;
					metSign = 0;
				}
				else if((expression[pos] == '-')||(expression[pos] == '+')){
					metSign = 1;
					metLeft = 0;
				}
				pos++;
			}
			else{
				//判断两次栈是否空，若空，说明输入非法，无法进行计算
				if(opNum.empty())
                    return false;
				back = opNum.top();
				opNum.pop();
				if(opNum.empty())
                    return false;
				front = opNum.top();
				opNum.pop();
				//判断一下分母是否为0
				if((opSign.top()=='/')&&(back == 0))
					return false;
				opNum.push(calculate(front,back,opSign.top()));
				opSign.pop();
				//这里pos不++继续进行判断
			}
		}
		//met number
		else{
			tempNum += expression[pos];
			pos++;
			metLeft = metSign = 0;
		}
	}
	cout<<"result"<<opNum.top()<<endl;
	return true;
}