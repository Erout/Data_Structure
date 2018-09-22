#include"Calculator.hpp"
#define Debug 0
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
	result_num = 0;
	result_head = NULL;
}
void Calculator::clear(){
	clearResult();
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
	first_head = second_head = NULL;
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
	if(coe == 0)
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
		if(temp->exponent == exp){
			existence = 1;
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
		if(temp->exponent == exp){
			existence = 1;
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
		if(temp->exponent == exp){
			existence = 1;
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
	bool firstItemAppear = 0;
	while(temp != NULL){
		if(temp->exponent == 0){
			cout<<temp->coefficient;
			firstItemAppear = 1;
		}
		else if(temp->exponent == 1){
			if(temp->coefficient == 1)
				cout<<"x";
			else if(temp->coefficient == -1)
				cout<<"-x";
			else
				cout<<temp->coefficient<<"x";
			firstItemAppear = 1;
		}
		else{
			if(temp->coefficient == 1)
				cout<<"x"<<"^"<<temp->exponent;

			else if(temp->coefficient == -1)
				cout<<"-x"<<"^"<<temp->exponent;
			else
				cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
			firstItemAppear = 1;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0))
			cout<<"+";
		temp = temp->next;
	}
	if(!firstItemAppear)
		cout<<"0";
	cout<<endl;

	temp = second_head;
	firstItemAppear = 0;
	while(temp != NULL){
		if(temp->exponent == 0){
			cout<<temp->coefficient;
			firstItemAppear = 1;
		}
		else if(temp->exponent == 1){
			if(temp->coefficient == 1)
				cout<<"x";
			else if(temp->coefficient == -1)
				cout<<"-x";
			else
				cout<<temp->coefficient<<"x";
			firstItemAppear = 1;
		}
		else{
			if(temp->coefficient == 1)
				cout<<"x"<<"^"<<temp->exponent;
			else if(temp->coefficient == -1)
				cout<<"-x"<<"^"<<temp->exponent;
			else
				cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
			firstItemAppear = 1;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0))
			cout<<"+";
		else
			cout<<" ";
		temp = temp->next;
	}
	if(!firstItemAppear)
		cout<<"0";
	cout<<endl;
}
void Calculator::showResult(){
	single* temp = result_head;
	bool firstItemAppear = 0;
	while(temp != NULL){
		if(temp->coefficient == 0){
			if((temp->next != NULL)&&(temp->next->coefficient > 0)&&(firstItemAppear))
				cout<<"+";
			temp = temp->next;
			continue;
		}
		if(temp->exponent == 0){
			cout<<temp->coefficient;
			firstItemAppear = 1;
		}
		else if(temp->exponent == 1){
			if(temp->coefficient == 1)
				cout<<"x";
			else if(temp->coefficient == -1)
				cout<<"-x";
			else
				cout<<temp->coefficient<<"x";
			firstItemAppear = 1;
		}
		else{
			if(temp->coefficient == 1)
				cout<<"x"<<"^"<<temp->exponent;
			else if(temp->coefficient == -1)
				cout<<"-x"<<"^"<<temp->exponent;
			else
				cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
			firstItemAppear = 1;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0))
			cout<<"+";
		temp = temp->next;
	}
	if(!firstItemAppear)
		cout<<"0";
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
}
bool Calculator::multiple(){
	//系数相乘，指数相加 
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
}
void Calculator::derivative(int id){
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
}
void Calculator::valueOfX(double x){
	double result1 = 0;
	single* temp1 = first_head;
	while(temp1 != NULL){
		result1 += temp1->coefficient*pow(x,temp1->exponent);
		temp1 = temp1->next;
	}
	double result2 = 0;
	single* temp2 = second_head;
	while(temp2 != NULL){
		result2 += temp2->coefficient*pow(x,temp2->exponent);
		temp2 = temp2->next;
	}
	cout<<"result1: "<<result1<<endl<<"result2: "<<result2<<endl;
}
void Calculator::sort(){
	single* p = first_head;
	single *p1 = p;
	int tempcoe,tempexp;
	for(p; p != NULL; p = p->next){
		for(p1 = p; p1 != NULL; p1 = p1->next){
			if(p->exponent < p1->exponent){
				tempcoe = p->coefficient;
				tempexp = p->exponent;
				p->coefficient = p1->coefficient;
				p->exponent = p1->exponent;
				p1->coefficient = tempcoe;
				p1->exponent = tempexp;
			} 			
		}
	}
	single* q = second_head;
	single* q1 = q;
	for(q; q != NULL; q = q->next){
		for(q1 = q; q1 != NULL; q1 = q1->next){
			if(q->exponent < q1->exponent){
				tempcoe = q->coefficient;
				tempexp = q->exponent;
				q->coefficient = q1->coefficient;
				q->exponent = q1->exponent;
				q1->coefficient = tempcoe;
				q1->exponent = tempexp;
			}
		}
	}
	single* r = result_head;
	single* r1 = r;
	for(r; r != NULL; r = r->next){
		for(r1 = r; r1 != NULL; r1 = r1->next){
			if(r->exponent <r1->exponent){
				tempcoe = r->coefficient;
				tempexp = r->exponent;
				r->coefficient = r1->coefficient;
				r->exponent = r1->exponent;
				r1->coefficient = tempcoe;
				r1->exponent = tempexp;
			}
		}
	}
}
string Calculator::getResult(){
    single* temp = result_head;
    char* c = new char[500];
    string s;
    bool firstItemAppear = 0;
    while(temp != NULL){
        if(temp->exponent == 0){
            //cout<<temp->coefficient;
            sprintf(c,"%.2lf",temp->coefficient);
            s += c;
            firstItemAppear = 1;
        }
        else if(temp->exponent == 1){
            if(temp->coefficient == 1){
                //cout<<"x";
                sprintf(c,"%c",'x');
                s += c;
            }
            else if(temp->coefficient == -1){
                //cout<<"-x";
                sprintf(c,"%c%c",'-','x');
                s += c;
            }
            else{
                //cout<<temp->coefficient<<"x";
                sprintf(c,"%.2lf%c",temp->coefficient,'x');
                s += c;
            }
            firstItemAppear = 1;
        }
        else{
            if(temp->coefficient == 1){
                //cout<<"x"<<"^"<<temp->exponent;
                sprintf( c,"%c%c%d",'x','^',temp->exponent);
                s += c;
            }
            else if(temp->coefficient == -1){
                //cout<<"-x"<<"^"<<temp->exponent;
                sprintf(c,"%c%c%c%d",'-','x','^',temp->exponent);
                s += c;
            }
            else{
                //cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
                sprintf(c,"%.2lf%c%c%d",temp->coefficient,'x','^',temp->exponent);
                s += c;
            }
            firstItemAppear = 1;
        }
        if((temp->next != NULL)&&(temp->next->coefficient > 0)){
            sprintf(c,"%c",'+');
            s += c;
            //cout<<"+";
        }
        temp = temp->next;
    }
    if(!firstItemAppear){
        sprintf(c,"%d",0);
        s += c;
        //cout<<"0";
    }
    return s;
}
string Calculator::getFirstInput(){
	sort();
	single* temp = first_head;
	bool firstItemAppear = 0;
	string s;
	char* c = new char[500];
	while(temp != NULL){
		if(temp->exponent == 0){
			//cout<<temp->coefficient;
			sprintf(c,"%.2lf",temp->coefficient);
			s += c;
			firstItemAppear = 1;
		}
		else if(temp->exponent == 1){
			if(temp->coefficient == 1){
				sprintf(c,"%c",'x');
				//cout<<"x";
				s += c;
			}
			else if(temp->coefficient == -1){
				sprintf(c,"%c%c",'-','x');
				//cout<<"-x";
				s += c;
			}
			else{
				//cout<<temp->coefficient<<"x";
				sprintf(c,"%.2lf%c",temp->coefficient,'x');
				s += c;
			}
			firstItemAppear = 1;
		}
		else{
			if(temp->coefficient == 1){
				//cout<<"x"<<"^"<<temp->exponent;
				sprintf(c,"%c%c%d",'x','^',temp->exponent);
				s += c;
			}

			else if(temp->coefficient == -1){
				sprintf(c,"%c%c%c%d",'-','x','^',temp->exponent);
				//cout<<"-x"<<"^"<<temp->exponent;
				s += c;
			}
			else{
				//cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
				sprintf(c,"%.2lf%c%c%d",temp->coefficient,'x','^',temp->exponent);
				s += c;
			}
			firstItemAppear = 1;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0)){
			//cout<<"+";
			s += '+';
		}
		temp = temp->next;
	}
	if(!firstItemAppear){
		//cout<<"0";
		s += '0'; 
	}
	//cout<<endl;
	return s;
}
string Calculator::getSecondInput(){
	sort();
	single* temp = second_head;
	bool firstItemAppear = 0;
	string s;
	char* c = new char[500];
	while(temp != NULL){
		if(temp->exponent == 0){
			//cout<<temp->coefficient;
			sprintf(c,"%.2lf",temp->coefficient);
			s += c;
			firstItemAppear = 1;
		}
		else if(temp->exponent == 1){
			if(temp->coefficient == 1){
				sprintf(c,"%c",'x');
				//cout<<"x";
				s += c;
			}
			else if(temp->coefficient == -1){
				sprintf(c,"%c%c",'-','x');
				//cout<<"-x";
				s += c;
			}
			else{
				//cout<<temp->coefficient<<"x";
				sprintf(c,"%.2lf%c",temp->coefficient,'x');
				s += c;
			}
			firstItemAppear = 1;
		}
		else{
			if(temp->coefficient == 1){
				//cout<<"x"<<"^"<<temp->exponent;
				sprintf(c,"%c%c%d",'x','^',temp->exponent);
				s += c;
			}

			else if(temp->coefficient == -1){
				sprintf(c,"%c%c%c%d",'-','x','^',temp->exponent);
				//cout<<"-x"<<"^"<<temp->exponent;
				s += c;
			}
			else{
				//cout<<temp->coefficient<<"x"<<"^"<<temp->exponent;
				sprintf(c,"%.2lf%c%c%d",temp->coefficient,'x','^',temp->exponent);
				s += c;
			}
			firstItemAppear = 1;
		}
		if((temp->next != NULL)&&(temp->next->coefficient > 0)){
			//cout<<"+";
			s += '+';
		}
		temp = temp->next;
	}
	if(!firstItemAppear){
		//cout<<"0";
		s += '0'; 
	}
	//cout<<endl;
	return s;

}