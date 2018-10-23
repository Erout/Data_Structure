/*辅助理解KMP算法*/
#include<iostream>
#include<string>
#define size 100
using namespace std;
int Index_KMP(string a, string b);
int main(){
	string a,b;
	cin>>a>>b;
	cout<<Index_KMP(a,b)<<endl;
	return 0;
}
int Index_KMP(string a, string b){
	int next[size];
	get_next(b,next);
	int i = 0;//i = pos
	int j = 1;
	while((i <= a[0])&&(j <= b[0])){
		if((j == 0) || (a[i] == b[j])){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
	if(j > b[0])
		return (i - b[0]);
	else
		return 0;
}
void get_next(string T, int next[]){
	int i = 1;
	next[1] = 0;
	int j = 0;
	while(i < T[0]){
		if((j == 0)||(T[i] == T[j])){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}
void get_nextval(string T, int nextval[]){
	int i = 1;
	nextval[1] = 0;
	int j = -1;
	while(i < T[0]){
		if((j==0)||(T[i] ==T[j])){
			i++;
			j++;
			if(T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}