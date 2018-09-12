#include"poly.hpp"
Poly::Poly(){
	num = 0;
	head = NULL;
	next = NULL;
}
Poly::Poly(string s){
	next = NULL;
	num = 0;
	head = tail = NULL;
	s += '+';
	string add;
	//if(s[0] != '-')
	//	add += '+';
	for(int i = 0; i < s.size(); i++){
		if((s[i] == '+')||(s[i] == '-')){
			AddPoly(add);
			add.clear();
	//		add += s[i];
		}
		else
			add += s[i];
	}
}
Poly::~Poly(){
	next = NULL;
	single* temp = head;
	while(temp != NULL){
		temp = temp->next;
		delete head;
		head = temp;
	}
	tail = NULL;
}
int StringToInt(string s){
	int total = 0;
	for(int i = 0; i < s.size(); i++){
		total += (s[i]-'0')*pow(10,s.size()-i-1);
	}
	return total;
}
void Poly::AddPoly(string s){
	if(s.size() == 0)
		return;
	int XPosition = -1;
	int coe,exp;
	num++;
	for(int i = 0; i < s.size();i++){
		if(s[i] == 'x')
			XPosition = i;
	}
	if(XPosition == -1){
		coe = StringToInt(s);
		exp = 0;
	}
	else if(XPosition == s.size()-1){
		coe = StringToInt(s.substr(0,XPosition));
		exp = 1;
	}
	else{
		coe = StringToInt(s.substr(0,XPosition));
		exp =StringToInt(s.substr(XPosition+1,s.size()-XPosition-1));
	}
	//23565x2165 
	if(head == NULL){
		head = new single(coe,exp);
		tail = head;
	}
	else{
		 tail->next = new single(coe,exp);
		 tail  = tail->next;
	}
}
void Poly::print(){
	cout<<"num:"<<num<<endl;
	single* temp = head;
	while(temp != NULL){
		cout<<temp->coefficient<<"x"<<temp->exponent<<endl;
		temp = temp->next;
	}
}
Poly* Poly::getNext(){
	return this->next;
}
void Poly::setNext(Poly* p){
	this->next = p;
}