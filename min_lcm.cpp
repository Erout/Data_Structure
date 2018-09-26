#include<iostream>
#include<cstring>
#include<cmath>
#define size 100000
using namespace std;
bool isOdd(int n){
	for(int i = 2; i < sqrt(n)+1; i++){
		if((n % i)==0)
			return false;
	}
	return true;
}
int main(){
	int N;
	cin>>N;
	int total = 1;
	int left = N;//1-N (left <= N)
	int M,Mtemp;
	M = Mtemp = N + 2;
	total = (N+1)*(N+2);
	while(left > 1){
		//cout<<endl;
		//cout<<"left:"<<left<<" ";
		if((isOdd(left))&&(M < 2*left)){
		//	cout<<"odd ";
			M = 2*left;
			for(int i = Mtemp+1;i<= M; i++)
				total *= i;
			Mtemp = M;
		}
		if((total % left)==0){
			total /= left;
			left--;
		}
		else{
		//	cout<<"M++ ";
			M = Mtemp = M+1;
			total *= M;
		}
	}
	cout<<M<<endl;
}