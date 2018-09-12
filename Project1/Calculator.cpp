#include"Calculator.hpp"
Calculator* Calculator::instance_ = NULL;
Calculator::Calculator(){
	first_head = NULL;
	second_head = NULL;
	first_num = 0;
	second_num = 0;
}
Calculator::~Calculator(){
	clear();
}
Calculator* Calculator::getInstance(){
	if(instance_ == NULL)
		instance_ = new Calculator;
	return instance_;
}
bool Calculator::deleteInstance(){
	clear();
	delete instance_;
	instance_ = NULL;
}
void Calculator::clear(){
	single* temp = first_head;
	while(temp != NULL){
		first_head = first_head->next;
		delete temp;
		temp = first_head;
	}
	temp = second_head;
	while(temp != NULL){
		second_head = second_head->next;
		delete temp;
		temp = second_head;
	}
	first_num = second_num = 0;
}
bool Calculator::addItem(string s, int id){
	if(s.size() == 0)
		return false;
	int xPosition = -1; 
	int coe,exp;
	for(int i = 0; i < s.size();i++){
		if(s[i] == 'x')
			xPosition = i;
	}
	if(xPosition == -1){
		coe = stringToInt(s);//带符号
		exp = 0;
	}
	else if(xPosition == s.size()){
		coe = stringToInt(s.substr(0,xPosition));
		exp = 1;
	}
	else{
		coe = stringToInt(s.substr(0,xPosition));
		exp = stringToInt(s.substr(xPosition+1,s.size()-xPosition-1))
	}
	if(id == 1)
		addItemToFirst(coe,exp);
	else if(id == 2)
		addItemToSecond(coe,exp);
	return true;
}
bool Calculator::addItemToFirst(int coe,int exp){
		single* temp = first_head;
		bool existence = 0;
	if(first_head == NULL)
		first_head  = new single(coe,exp);
	else{
		while(temp->next != NULL){
			if(temp->exponent ==exp){
				existence = 1;
				break;
			}
			temp = temp->next;
		}
		if(existence == 1){
			temp->coefficient += coe;
		}
		else
			temp->next = new single(coe,exp);
	}
	first_num++;
	return true;
}
bool Calculator::addItemToSecond(int coe,int exp){
		single* temp = first_head;
		bool existence = 0;
	if(second_head == NULL)
		second_head = new single(coe,exp);
	else{
		while(temp->next != NULL){
			if(temp->exponent == exp){
				existence = 1;
				break;
			}
			temp = temp->next;
		}
		if(existence == 1){
			temp->coefficient += coe;
		}
		else
			temp->next = new single(coe,exp);
	}
	second_num++;
	return true;
}
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
void Calculator::display(){
	single* temp = first_head;
	while(temp != NULL){
		cout<<temp->coe<<"x"<<temp->exp<<"+";
		temp = temp->next;
	}
	cout<<endl;
	temp = second_head;
	while(temp != NULL){
		cout<<temp->coe<<"x"<<temp->exp<<"+";
		temp = temp->next;
	}
}
bool Calculator::add(){
	single* temp1 = first_head;
	single* temp2 = second_head;
	
}
void Calculator::sort(){

}