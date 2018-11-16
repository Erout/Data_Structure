#include<iostream>
#define Size 1000
using namespace std;
int main(){
	int m,n,x,y;
	cin>>m>>n>>x>>y;
	int matrix[Size][Size];
	int max = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>matrix[i][j];
		}
	}
	int sum = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			sum = 0;
			if(((i+x) <= m)&&((j+y) <= n)){
				for(int k = i; k < i+x; k++){
					for(int q = j; q < j+y; q++){
						sum += matrix[k][q];
					}
				}
			}
			if(sum > max)
				max = sum;
		}
	}
	cout<<max<<endl;
}