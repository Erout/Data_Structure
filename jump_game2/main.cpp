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
	int equalLast = n-1;//等价于最后一跳的
	//从equallast向前寻找能跳到它的最前的格子
	int count;
	int min;
	int step = 0;
	while(equalLast != 0){
		min = equalLast;
		for(count = equalLast; count >= -1; count--){
			if(count == -1)
				break;
			if(arr[count] >= (equalLast-count)){
				min = count;
			}
		}
		if(min == equalLast){
			cout<<-1<<endl;
			return 0;
		}
		equalLast = min;
		step++;
	}
	cout<<step<<endl;

}