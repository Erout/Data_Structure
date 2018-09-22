//test for display,sort and input
#include<iostream>
#include"Calculator.hpp"
using namespace std;
int main(){
	Calculator ca;
	string s1 ="5x +6x^2 +3 -5x^5";
	string s2 ="2x^5 -7x -9x^100 +8x^8 +6x";
	ca.Input(s1,1);
	ca.Input(s2,2);
	ca.display();
	ca.sort();
	ca.display();

	//ca.valueOfX(-1.6);
	//cout<<"MULTIPLE"<<endl;
	//ca.showResult();
	ca.subtract();
	cout<<"SUB"<<endl;
	ca.sort();
	cout<<ca.getResult();
	ca.add();
	cout<<"ADD"<<endl;
	ca.sort();
	cout<<ca.getResult();
}
/*
(1)	 
(2)	 "6x^-3 -x +4.4x^2 -1.2x^9" "-6x^-3 +5.4x^2 -x^2 +7.8x^15"
(3)	 "x +x^3" "-x -x^3"
(4)	 
(5)	 
(6)	 
*/