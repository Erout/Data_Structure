#include<iostream>
#define SIZE 1005
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ingredient[SIZE];
	int bake[SIZE];
	int cancook[SIZE] = {0};
	int material = 0;
	for(int i = 1; i <= n; i++){
		cin>>bake[i];
		material += bake[i];
	}
	//calculate maximal number of cookie not use magic powder
	int maximal = 99999;
	for(int i = 1; i <= n; i++){
		cin>>ingredient[i];
		cancook[i] = (ingredient[i]-(ingredient[i]%bake[i]))/bake[i];
		if(cancook[i] < maximal)
			maximal = cancook[i];
	}
	int cookies = maximal;
	for(int i = 1; i <= n; i++){
		ingredient[i] -= maximal*bake[i];
		cancook[i] -= maximal;
	}
	while(k > 0){
		for(int i = 1; i <= n; i++){
			if(cancook[i] == 0){
				k -= (bake[i]-ingredient[i]);
				ingredient[i] = 0;
			}
			else{
				cancook[i] -= 1;
				ingredient[i] -= bake[i];
			}
		}
		if(k >= 0)
			cookies += 1;
	}
	cout<<cookies<<endl;
}