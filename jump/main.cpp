#include<iostream>
#define size 1000000
using namespace std;
int main(){
	int n;
	int arr[size];
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int max = n-1;
	int count;
	cout<<"max:"<<max<<" count:"<<count<<endl;
	for(count = max; count >= 0; --count){
		if(arr[count]>=(max-count)){
			max = count;
			cout<<"max:"<<max<<" count:"<<count<<endl;
		}
	}
	if(max == 0)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}