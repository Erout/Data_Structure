#include<iostream>
#include<cstring>
#define size 100000
using namespace std;
int main(){
	int N;
	cin>>N;
	int M = N+2;
	bool status[size];
	if(M < 2*N)
		M = 2*N;
	memset(status,0,sizeof(status));
	for(int i = N; i > 0; i++){
		for(int j = M; j > N; j--){
			if(j % i == 0){
				status[i]==true;
				break;
			}
		}
		if(status == false)
	}
}