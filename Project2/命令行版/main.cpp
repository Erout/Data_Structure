#include<iostream>
#include"StackCal.h"
using std::cout;
using std::cin;
using std::endl;
int main(){
	StackCal sc;
	string s;
	int act;
	cout<<"请输入操作：0->退出系统 1->进行计算"<<endl;
	cin>>act;
	while(act){
		cout<<"请输入要计算的表达式"<<endl;
		cin>>s;
		sc.clear();
		sc.Input(s);
		if(!sc.compute())
			cout<<"invalid!"<<endl;
		cout<<"请输入操作：0->退出系统 1->进行计算"<<endl;
		cin>>act;
	}

	return 0;
}