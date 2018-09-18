//test for display,sort and input
#include<iostream>
#include"Calculator.hpp"
using namespace std;
int main(){
	Calculator ca;
	string s1 ="x +x^3";
	string s2 ="-x -x^3";
	ca.Input(s1,1);
	ca.Input(s2,2);
	ca.display();
	//ca.add();
	//cout<<"ADD"<<endl;
	//ca.showResult();
	ca.subtract();
	cout<<"SUB"<<endl;
	ca.showResult();
}
/*
(1)	 
(2)	 "6x^-3 -x +4.4x^2 -1.2x^9" "-6x^-3 +5.4x^2 -x^2 +7.8x^15"
(3)	 
(4)	 
(5)	 
(6)	 
*/