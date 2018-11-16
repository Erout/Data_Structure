/*非递归akm*/
#include<iostream>
#include<stack>
using namespace std;
struct my
{
	int mval;
	int nval;
};
int akm(int m, int n);
int main(){
	akm(2,3);
}
int akm(int m, int n){
	int top = 0;
	my St[10000];
	St[top].mval = m;
	St[top].nval = n;
	do{
		cout<<"big loop"<<endl;
		while(St[top].mval){
			cout<<"loop"<<endl;
			while(St[top].nval){
				top++;
				St[top].mval = St[top-1].mval;
				St[top].nval = St[top-1].nval-1;

				for(int i = 0; i < top; i++){
					cout<<"m:"<<St[i].mval<<" n:"<<St[i].nval<<"  ";
				}
				cout<<endl;
			}
			St[top].mval--;
			St[top].nval = 1;
			for(int i = 0; i < top; i++){
				cout<<"m:"<<St[i].mval<<" n:"<<St[i].nval<<"  ";
			}
			cout<<endl;
		}
		if(top > 0){
			top--;
			St[top].mval--;
			St[top].nval = St[top+1].nval+1;
			cout<<"if part"<<endl;
			for(int i = 0; i < top; i++){
				cout<<"m:"<<St[i].mval<<" n:"<<St[i].nval<<"  ";
			}
			cout<<endl;
			cout<<endl;
		}
	}while((top != 0)||(St[top].mval != 0));
	return (St[top].nval + 1);
}
