#include<iostream>
#include"StackCal.h"
void welcome(){
	cout<<"欢迎使用表达式计算器！"<<endl;
	cout<<"这是简易命令行版本"<<endl;
	cout<<"请输入操作：0->退出系统 1->进行计算"<<endl;
}
int main(){
	StackCal sc;
	string s;
	int act;
	cin>>act;
	while(act){
		cout<<"请输入要计算的表达式"<<endl;
		cin>>s;
		sc.clear();
		sc.Input(s);
		sc.compute();
		cout<<"请输入操作：0->退出系统 1->进行计算"<<endl;
		cin>>act;
	}

	return 0;
}