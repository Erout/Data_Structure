#include<iostream>
#include<stdio.h>
#include<string.h>
#define Pos 11
#define Time 100000
#define Debug 1
using namespace std;
int Maximun(int a,int b,int c = 0){
	if((a >= b) &&(a >= c))
		return a;
	if((b >= a) &&(b >= c))
		return b;
	return c;
}
int main(){
	int cake[Pos][Time];
	memset(cake,0,sizeof(cake));
	int n,x,T;
	int maxTime = 0;
	scanf("%d",&n);
	//cin>>n;
	if(n){
		while(n--){
		scanf("%d %d",&x,&T);
		//cin>>x>>T;
		cake[x][T]++;
		maxTime = Maximun(maxTime, T);
		}
		if(Debug){
			cout<<"x:"<<x<<" T:"<<T<<"maxtime:"<<maxTime<<endl;
			for(int i = 0;i < Pos; i++){
				for(int j = 0; j < maxTime+1; j++)
					cout<<cake[i][j]<<" ";
				cout<<endl;
			}
		}
		for(int i = maxTime; i > 0; i--){
			for(int j = 0; j < 11; j++){
				if(j == 0)
					cake[j][i-1] += Maximun(cake[j][i],cake[j+1][i]);
				else if(j == 10)
					cake[j][i-1] += Maximun(cake[j][i],cake[j-1][i]);
				else
					cake[j][i-1] += Maximun(cake[j][i],cake[j-1][i],cake[j+1][i]);
			}
					if(Debug){
						cout<<"x:"<<x<<" T:"<<T<<"maxtime:"<<maxTime<<endl;
						for(int i = 0;i < Pos; i++){
							for(int j = 0; j < maxTime+1; j++)
								cout<<cake[i][j]<<" ";
							cout<<endl;
						}
					}
		}
	}
		cout<<cake[5][0]<<endl;
}
/*conclusion
动态规划
从下往上计算，算得每一步可取的最大值
*/