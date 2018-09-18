#include"Calculator.hpp"
#define Debug 1
Calculator* Calculator::instance_ = NULL;
Calculator::Calculator(){
	first_head = NULL;
	second_head = NULL;
	result_head = NULL;
	first_num = 0;
	second_num = 0;
	result_num = 0;
}
Calculator::~Calculator(){
	clear();
}
Calculator* Calculator::getInstance(){
	if(instance_ == NULL)
		instance_ = new Calculator;
	return instance_;
}
/*
bool Calculator::deleteInstance(){
	clear();
	delete instance_;
	instance_ = NULL;
}
*/

int stringToInt(string s){
	if(Debug){
		cout<<"ToInt:"<<s<<"END"<<endl;
	}
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
double stringToDouble(string s){
	if(Debug){
		cout<<"ToDouble:"<<s<<"END"<<endl;
	}
	double total = 0;
	int sign;
	string ns;
	if(s[0] =='-'){
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
	int pointP = -1;
	for(int i = 0; i < ns.size();i++){
		if(ns[i] =='.')
			pointP = i;
	}
	total += stringToInt(ns.substr(0,pointP));
	int cal = -1;
	if(pointP != -1){
		for(int i = pointP+1; i < ns.size(); i++){
			total += (ns[i]-'0')*pow(10,cal);
			cal--;
		}
	}
	if(sign == 0)
		return total;
	else
		return -total;
}
void Calculator::clearResult(){
	single* temp = result_head;
	while(temp != NULL){
		result_head = result_head->next;
		delete temp;
		temp = result_head;
	}
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
bool Calculator::Input(string s, int id){
	s += ' ';
	string temp;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			addItem(temp,id);
			if(Debug){
				cout<<"input-temp:"<<temp<<"END"<<endl;
			}
			temp.clear();
		}
		else{
			temp += s[i];
		}
	}
	return true;
}
//单项
bool Calculator::addItem(string s, int id){
	if(Debug){
		cout<<"addItem:"<<s<<"id"<<id<<"END"<<endl;
	}
	if(s.size() == 0)
		return false;
	int xPosition = -1; 
	int expPosition = -1;
	double coe;
	int exp;
	for(int i = 0; i < s.size();i++){
		if(s[i] == 'x')
			xPosition = i;
		if(s[i] == '^')
			expPosition = i;
	}
	if(xPosition == -1){
		exp = 0;
		coe = stringToDouble(s);
	}
	else if(xPosition == 0){
		coe = 1;
		if(expPosition == -1)
			exp = 1;
		else
			exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
	}
	else if((xPosition == 1)&&(s[0] == '-')){
		coe = -1;
		if(expPosition == -1)
			exp = 1;
		else
			exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
	}
	else if((xPosition == 1)&&(s[0] == '+')){
		coe = 1;
		if(expPosition == -1)
			exp = 1;
		else
			exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
	}
	else{
		if(expPosition == -1){
			exp = 1;
			coe = stringToDouble(s.substr(0,xPosition));
		}
		else{
			exp = stringToInt(s.substr(expPosition+1,s.size()-expPosition-1));
			coe = stringToDouble(s.substr(0,xPosition));
		} 		
	}
	if((coe == 0)&&(exp == 0))
		return false;
	if(id == 1)
		addItemToFirst(coe,exp);
	else if(id == 2)
		addItemToSecond(coe,exp);
	else if(id == 3)
		addItemToThird(coe,exp);
	return true;
}
bool Calculator::addItemToThird(double coe,int exp){
	if((coe == 0)&&(exp == 0))
		return false;
	single* temp = result_head;
	bool existence = 0;
	if(result_head == NULL)
		result_head = new single(coe,exp);
	else{
		while(temp->next != NULL){
			if(temp->exponent == exp){
				existence = 1;
				break;
			}
			temp = temp->next;
		}
		if(existence == 1)
			temp->coefficient += coe;
		else
			temp->next = new single(coe,exp);
	}
	result_num++;
	return true;
}
bool Calculator::addItemToFirst(double coe,int exp){
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
bool Calculator::addItemToSecond(double coe,int exp){
		single* temp = second_head;
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

void Calculator::display(){
	//sort();
	single* temp = first_head;
	while(temp != NULL){
		if(temp->exponent == 0)
			cout<<temp->coefficient;
		else if(temp->exponent == 1){
			if(temp->coefficient == 1)
				cout<<"x";
			else if(temp->coefficient == -1)
				cout<<"-x";
			else
				cout<<temp->coefficient<<"x";
		}
		else{
			if(temp->coefficient == 1)
				cout<<"x"<<"^"<<temp->exponent;
			else if(temp->coefficient == -1)
				cout<<"-x"<<"^"<<temp->exponent;
			else
				cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0))
			cout<<"+";
		temp = temp->next;
	}
	cout<<endl;
	temp = second_head;
	while(temp != NULL){
		if(temp->exponent == 0)
			cout<<temp->coefficient;
		else if(temp->exponent == 1){
			if(temp->coefficient == 1)
				cout<<"x";
			else if(temp->coefficient == -1)
				cout<<"-x";
			else
				cout<<temp->coefficient<<"x";
		}
		else{
			if(temp->coefficient == 1)
				cout<<"x"<<"^"<<temp->exponent;
			else if(temp->coefficient == -1)
				cout<<"-x"<<"^"<<temp->exponent;
			else
				cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0))
			cout<<" +";
		else
			cout<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void Calculator::showResult(){
	single* temp = result_head;
	while(temp != NULL){
		if(temp->coefficient == 0){
			temp = temp->next;
			continue;
		}
		if(temp->exponent == 0)
			 cout<<temp->coefficient;
		else if(temp->exponent == 1){
			if(temp->coefficient == 1)
				cout<<"x";
			else if(temp->coefficient == -1)
				cout<<"-x";
			else
				cout<<temp->coefficient<<"x";
		}
		else{
			if(temp->coefficient == 1)
				cout<<"x"<<"^"<<temp->exponent;
			else if(temp->coefficient == -1)
				cout<<"-x"<<"^"<<temp->exponent;
			else
				cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0))
			cout<<"+";
		temp = temp->next;
	}
	cout<<endl;
}
bool Calculator::add(){
	//string s,total;
	clearResult();
	single* temp1 = first_head;
	single* temp2 = second_head;
	while(temp1 != NULL){
		addItemToThird(temp1->coefficient,temp1->exponent);
		temp1 = temp1->next;
	}
	while(temp2 != NULL){
		addItemToThird(temp2->coefficient,temp2->exponent);
		temp2 = temp2->next;
	}
	/*while((temp1 != NULL)&&(temp2 != NULL)){
		if(temp1->exponent == temp2->exponent){
			sprintf(s,"%d%c%d",temp1->coefficient+temp2->coefficient,'x',temp1->exponent);
			total += s;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->exponent > temp2->exponent){
			sprintf(s,"%d%c%d",temp1->coefficient,'x',temp1->exponent);
			total += s;
			temp1 = temp1->next;
		}
		else{
			sprintf(s,"%d%c%d",temp2->coefficient,'x',temp2->exponent);
			total += s;
			temp2 = temp2->next;
		}
	}
	if(temp1 == NULL){
		while(temp2 != NULL){
			sprintf(s,"%d%c%d",temp2->coefficient,'x',temp2->exponent);
			total += s;
			temp2 = temp2->next;
		}
	}
	if(temp2 == NULL){
		while(temp1 != NULL){
			sprintf(s,"%d%c%d",temp1->coefficient,'x',temp1->exponent);
			total += s;
			temp1 = temp1->next;
		}
	}
	cout<<total;*/

	return true;
}
bool Calculator::subtract(){
	clearResult();
	single* temp1 = first_head;
	single* temp2 = second_head;
	while(temp1 != NULL){
		addItemToThird(temp1->coefficient,temp1->exponent);
		temp1 = temp1->next;
	}
	while(temp2 != NULL){
		addItemToThird(-temp2->coefficient,temp2->exponent);
		temp2 = temp2->next;
	}
	/*string s,total;
	while((temp1 != NULL)&&(temp2 != NULL)){
		if(temp1->exponent == temp2->exponent){
			sprintf(s,"%d%c%d",temp1->coefficient-temp2->coefficient,'x',temp1->exponent);
			total += s;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->exponent < temp2->exponent){
			sprintf(s,"%d%c%d",-temp2->coefficient,'x',temp2->exponent);
			total += s;
			temp2 = temp2->next;
		}
		else{
			sprintf(s,"%d%c%d",temp1->coefficient,'x',temp1->exponent);
			total += s;
			temp1 = temp1->next;
		}
	}
	if(temp1 == NULL){
		while(temp2 != NULL){
			sprintf(s,"%d%c%d",-temp2->coefficient,'x',temp2->exponent);
			total += s;
			temp2 = temp2->next;
		}
	}
	if(temp2 == NULL){
		while(temp1 != NULL){
			sprintf(s,"%d%c%d",temp1->coefficient,'x',temp1->exponent);
			total += s;
			temp1 = temp1->next;
		}
	}*/
}
bool Calculator::multiple(){
	//系数相乘，指数相加 
	//int arr[100][2];
	//int count = 0;
	clearResult();
	single* p = first_head;
	single* q = second_head;
	while(p != NULL){
		q = second_head;
		while(q != NULL){
			addItemToThird(p->coefficient*q->coefficient,p->exponent+q->exponent);
			q = q->next;
		} 
		p = p->next;
	}
	/*while(p != NULL){
		q = second_head;
		while(q != NULL){
			arr[count][0] = p->coefficient*q->coefficient;//coefficient
			arr[count][1] = p->exponent+q->exponent;//exponent
			q = q->next;
		}
		p = p->next;
	}*/
	//根据arr[i][1]进行排序和合并,再输出；
}
void Calculator::derivative(int id){
	//string s,total;
	clearResult();
	single* temp1 = first_head;
	single* temp2 = second_head;
	if(id == 1){
		while(temp1 != NULL){
			addItemToThird(temp1->coefficient*temp1->exponent,temp1->exponent-1);
			temp1 = temp1->next;
		}
	}
	else if(id == 2){
		while(temp2 != NULL){
			addItemToThird(temp2->coefficient*temp2->exponent,temp2->exponent-1);
			temp2 = temp2->next;
		}
	}
	/*while(temp1 != NULL){
		if(temp1->exponent){
			sprintf(s,"%d%c%d",temp1->coefficient*temp1->exponent,'x',temp1->exponent-1);
			temp1 = temp1->next;
		}
	}
	while(temp2 != NULL){
		if(temp2->exponent){
			sprintf(s,"%d%c%d",temp2->coefficient*temp2->exponent,'x',temp2->exponent-1);
			temp2 = temp2->next;
		}
	}*/
}
void Calculator::valueOfX(int x){
	int result1 = 0;
	single* temp1 = first_head;
	while(temp1 != NULL){
		result1 += temp1->coefficient*pow(x,temp1->exponent);
		temp1 = temp1->next;
	}
	int result2 = 0;
	single* temp2 = second_head;
	while(temp2 != NULL){
		result2 += temp2->coefficient*pow(x,temp2->exponent);
	}
	cout<<"result1"<<result1<<endl<<"result2"<<result2<<endl;
}
void Calculator::sort(){
	single* p = first_head;
	int tempcoe,tempexp;
	for(int i = 0; i < first_num;i++){
		p = first_head;
		while(p->next != NULL){
			if(p->exponent < p->next->exponent){
				tempcoe = p->coefficient;
				tempexp = p->exponent;
				p->coefficient = p->next->coefficient;
				p->exponent = p->next->exponent;
				p->next->coefficient = tempcoe;
				p->next->exponent = tempexp;
			}
			p = p->next;
		}
	}
	single* q = second_head;
	for(int i = 0; i < second_num; i++){
		q = second_head;
		while(q->next != NULL){
			if(q->exponent < p->next->exponent){
				tempcoe = q->coefficient;
				tempexp = q->exponent;
				q->coefficient = q->next->coefficient;
				q->exponent = q->next->exponent;
				q->next->coefficient = tempcoe;
				q->next->exponent = tempexp;
			}
			q = q->next;
		}
	}
}