#include<iostream>
#define size 100002
using namespace std;
int main() {
	int n,d;
	cin>>n>>d;
	int pos[size];
	long long count = 0;
	int exd = 0;
	for(int i = 0; i < n; i++){
		cin>>pos[i];
		if(i > 1){
			while(pos[i]-pos[exd] > d)
				exd++;
			//calculate C (i-exd) 2
			count += ((i-exd)*(i-exd-1))/(2);
		}
	}
	cout<<count<<endl;
}