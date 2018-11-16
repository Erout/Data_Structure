#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#define Size 300
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	int k;
	//s = "Computer and data science";
	//k = 1;
	string temp;
	int times[Size];
	char c;
	int first = 1;
	int onec = 1;
	for(int i = 0; i < n; i++){
		s = "";
		onec = 1;
		while(((cin>>temp)&&(!((temp[temp.size()-1] >='0')&&(temp[temp.size()-1] <= '9')))||(temp.size() != 1))){
			if(onec){
				s += temp;
				onec = 0;
			}
			else{
				s += " ";
				s += temp;
			}
		}
		k = temp[temp.size()-1]-'0';
		memset(times,0,sizeof(times));
		first = 1;
		for(int i = 0; i < s.size();i++){
			times[s[i]]++;
		}
		for(int i = 0; i < Size; i++){
			if(times[i] == k){
				c = i;
				if(!first)
					cout<<","<<"'"<<c<<"'";
				else{
					first = 0;
					cout<<"'"<<c<<"'";
				}
			}
		}
		cout<<endl;
	}
}