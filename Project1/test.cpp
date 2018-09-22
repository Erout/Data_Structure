#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char* c = new char[1000];
	double r = 3.142;
	int a = 26;
	string s ="-x" ;
	char ch = 'b';
	sprintf(c,"%lf%c%d",r,ch,a);
	string k = c;
	cout<<k;
	return 0;
}