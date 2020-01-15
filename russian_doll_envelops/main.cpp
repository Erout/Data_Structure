#include<iostream>
#include<algorithm>
#define SIZE 300005
using namespace std;
int partition(int env[][2], int low,int high){
	int key1 = env[low][0];
	int key2 = env[low][1];
	while(low < high){
		while(low < high && env[high][0] >= key1)
			high--;
		env[low][0] = env[high][0];
		env[low][1] = env[high][1];
		while(low < high && env[low][0] <= key1)
			low++;
		env[high][0]  = env[low][0];
		env[high][1]  = env[low][1];
	}
	env[low][0] = key1;
	env[low][1] = key2;
	return low;
}
void QucikSort(int env[][2], int low, int high){
	if(low < high){
		int pivot = partition(env,low,high);
		QucikSort(env,low,pivot-1);
		QucikSort(env,pivot+1,high);
	}
}
int main(){
	int n;
	int env[SIZE][2];
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>env[i][0]>>env[i][1];
	}
	QucikSort(env,0,n-1);
	cout<<"env:"<<endl;
	for(int i = 0; i < n; i++)
		cout<<env[i][0]<<" "<<env[i][1]<<endl;
	int prewidth = 99999,prehigh = 99999;
	int ans = 0;
	for(int i = n-1; i > -1; i--){
		if(env[i][0] < prewidth && env[i][1] < prehigh){
			int j = i;
			int maxhigh = 0;
			while(env[j][0] == env[i][0]){
				if(env[j][1] > maxhigh && env[j][1] < prehigh)
					maxhigh = env[j][1];
				j--;
			}
			prewidth = env[i][0];
			prehigh = maxhigh;
			ans++;
		}
	}
	cout<<ans<<endl;
}
//sort according to width
