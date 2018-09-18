#include<iostream>
#include<string>
//test for two function
#include"Calculator.hpp"
#define Debug 0
using std::string;
using std::cin;
using std::cout;
using std::endl;

int stringToInt(string s);
double stringToDouble(string s);
int main(){
	/*string s1 ="3x^2 +5x^6 +6x";
	string s2 ="9x^2 +5x +6x^3 +89";
	string s3 ="9x6+151x323564-113x32+131x123";
	Calculator ca;
	ca.Input(s1,1);
	ca.Input(s2,2);
	ca.display();*/
	string s1 = "+65";
	string s2 = "-98";
	string s3 = "-0.25";
	string s4 = "-2.3564";
	string s5 = "-5.000";
	string s6 = "91.134564";
	string s7 = "7";
	//cout<<stringToInt(s1)<<endl;
	//cout<<stringToInt(s2)<<endl;
	//cout<<stringToInt(s3)<<endl;
	cout<<stringToDouble(s1)<<endl;
	cout<<stringToDouble(s7)<<endl;
	//cout<<stringToDouble(s4)<<endl;
	//cout<<stringToDouble(s6)<<endl;
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
/*多项式格式：
 (+/-)coe X ^ (+/-)exp (+/-)coe X ^(+/-)exp (+/-)coe X ^ (+/-)exp
 if(x exits){
	if(^ exist){
		exp = 
	}
	else{
		exp = 1
	}
else{
	exp = 0;
 }
}
*/