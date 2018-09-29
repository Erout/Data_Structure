#include<iostream>
#include<cstring>
#define size 30
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	long long int arr[size][size];
	memset(arr,0,sizeof(arr));
	arr[0][0] = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i == 0){
				if(j != 0)
					arr[i][j] = arr[i][j-1];
			}
			else if(j == 0){
				if(i != 0)
					arr[i][j] = arr[i-1][j];
			}
			else
				arr[i][j] = arr[i-1][j]+arr[i] [j-1];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<arr[m-1][n-1]<<endl;
}