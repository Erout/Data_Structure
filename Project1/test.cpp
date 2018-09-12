#include<iostream>
#include<string>
#include"poly.hpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(){
	string s1 ="3x2+5x6+6x";
	string s2 ="9x2+5x+6x3+89";
	string s3 ="9x6+151x323564-113x32+131x123";
	Poly p1(s1);
	Poly p2(s2);
	Poly p3(s3);
	p1.print();
	p2.print();
	p3.print();
}