#include<iostream>
#include<string>
#include"Calculator.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
void welcome();
void goodBye();
int main(){
	int act;
	double x;
	bool status = true;
	string poly1,poly2;
	Calculator ca;
	welcome();
	while(1){
		cout<<"请输入操作"<<endl;
		cin>>act;
		switch(act){
			case 0:
				status = false;
				break;
			case 1:
				cout<<"请输入多项式1号"<<endl;
				getchar();
				getline(cin,poly1);
				ca.Input(poly1,1);
				cout<<"请输入多项式2号"<<endl;
				getline(cin,poly2);
				ca.Input(poly2,2);
				cout<<"输入成功！"<<endl;
				break;
			case 2:
				cout<<"按指数降序输出的结果为："<<endl;
				ca.display();
				break;
			case 3:
				ca.add();
				cout<<"相加结果为："<<endl;
				ca.showResult();
				break;
			case 4:
				ca.subtract();
				cout<<"相减结果为："<<endl;
				ca.showResult();
				break;
			case 5:
				ca.multiple();
				cout<<"相乘结果为："<<endl;
				ca.showResult();
				break;
			case 6:
				ca.derivative(1);
				cout<<"1号多项式求导结果为："<<endl;
				ca.showResult();
				ca.derivative(2);
				cout<<"2号多项式求导结果为："<<endl;
				ca.showResult();
				break;
			case 7:
				cout<<"请输入要带入的x值"<<endl;
				cin>>x;
				cout<<"1号多项式的值为："<<endl;
				cout<<ca.valueOfX(x,1);
				cout<<"2号多项式的值为："<<endl;
				cout<<ca.valueOfX(x,2);
				break;
			default:
				break;
		}
		if(!status)
			break;
	}
	goodBye();
	return 0;
}
void welcome(){
	cout<<"多项式计算器"<<endl;
	cout<<"请输入对应数字进行相应操作"<<endl;
	cout<<"0:退出系统"<<endl;
	cout<<"1:输入多项式"<<endl;
	cout<<"2:按指数降序输出您输入的多项式"<<endl;
	cout<<"3:两式相加"<<endl;
	cout<<"4:1号减2号"<<endl;
	cout<<"5:两式相乘"<<endl;
	cout<<"6:求导"<<endl;
	cout<<"7:带入x值"<<endl;
	cout<<"本计算器输入多项式的格式为："<<endl;
	cout<<"c1X^e1 c2X^e2 c3X^e3 ..."<<endl;
	cout<<"其中c1，c2，c3为带符号的系数（正号或负号）；e1，e2，e3为指数，每输入完一项请输入空格后再输入下一项"<<endl;
	cout<<"例如： 5x^8 +4.3x^4 -1.6x^2 -2x^-3"<<endl; 
}
void goodBye(){
	cout<<"感谢您使用本计算器！"<<endl;
	cout<<"GoodBye~"<<endl;
}