//dp correct
#include<iostream>
#include<string>
#define SIZE 100
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size() != s2.size()){
		cout<<0<<endl;
		return 0;
	}
	if(s1 == s2){
		cout<<1<<endl;
		return true;
	}
	int n = s1.size();
	bool dp[SIZE][SIZE][SIZE] = {0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			dp[i][j][1] = (s1[i] == s2[j]);
	}
	for(int len = 2; len <= n; len++){
		for(int i = 0; i <= n-len; i++){
			for(int j = 0; j <= n-len; j++){
				for(int k = 1; k < len; k++){
					if((dp[i][j][k]&&dp[i+k][j+k][len-k]) || (dp[i+k][j][len-k]&&dp[i][j+len-k][k]))
						dp[i][j][len] = 1;
				}
			}
		}
	}
	cout<<dp[0][0][n]<<endl;
}