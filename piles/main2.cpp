#include<iostream>
#include<algorithm>
#define size 50
using namespace std;
int main(){
	int n;
	int weight[size];
	int dp[size*100];
	int sum = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>weight[i];
		sum += weight[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = sum/2; j >= weight[i];j--){
			dp[j] = max(dp[j],dp[j-weight[i]]+weight[i]);
		}
	}
	cout<<abs(dp[sum/2]-(sum-dp[sum/2]))<<endl;
}