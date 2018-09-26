#include<iostream>
#include<cstring>
#define size 100
#define Debug 0
using namespace std;
int Partition(int arr[][2],int low,int high);
void QuickSort(int arr[][2],int low,int high);
int main(){
	int n,r,K;
	cin>>n>>r>>K;
	int tower[size][2];
	int defence[size];
	memset(tower,0,sizeof(tower));
	memset(defence,0,sizeof(defence));
	for(int i = 0; i < n; i++){
		//tower[i][0] = i;
		//cin>>tower[i][1];
		cin>>defence[i];
	}
	int up,down;
	for(int i = 0; i < n; i++){
		tower[i][0] = i;
		if((i - r) >= 0)
			up = i - r;
		else
			up = 0;
		if((i + r) < n)
			down = i + r;
		else
			down = n-1;
		for(int j = up; j <= down; j++){
			tower[j][1] += defence[i];
		}
	}
	//n >= 2r ->add 2rK each max add K 总共增加防御力为2rK 单个塔最多增加K
	//最低的防御塔之间距离大于2r 则需消耗两个弓箭手
	//n < 2r every can add K 每一个塔都可以增加K的防御值
	QuickSort(tower,0,n-1);
	if(n <= 2*r+1){
		cout<<tower[0][1]+K<<endl;
		return 0;
	}
	int border1,border2;
	for(int i = 0; i < K; i++){
		border1 =border2 = tower[0][0];
		//smallest and farthest
		for(int j = 1; j < n; j++){
			if((border2-border1)<2*r){
				if((tower[j][0]<border1)&&((border2-tower[j][0])<=2*r)){
					border1 = tower[j][0];
				}
				if((tower[j][0]>border2)&&((tower[j][0]-border1)<=2*r)){
					border2 = tower[j][0];
				}
			}
			if((border2-border1)==2*r)
				break;
		}
			//border means id but id is not organized
		for(int q = 0; q <n; q++){
			if((tower[q][0]>border1)&&(tower[q][0]<border2)){
				tower[q][1]++;
			}
			else if((tower[q][0]==border1)||(tower[q][0] ==border2)){
				tower[q][1]++;
			}
			
		}
		QuickSort(tower,0,n-1);
	}
	if(Debug){
		for(int i = 0; i < n; i++){
			cout<<"Tower id:"<<tower[i][0]<<" Tower defence:"<<tower[i][1] <<endl;
		}
	}
	cout<<tower[0][1]<<endl;
}
void QuickSort(int arr[][2],int low,int high){
	if(low < high){
		int mid = Partition(arr,low,high);
		QuickSort(arr,low,mid-1);
		QuickSort(arr,mid+1,high);
	}
}
int Partition(int arr[][2],int low,int high){
	int key1 = arr[low][1];
	int key0 = arr[low][0];
	while(low < high){
		while((low < high)&&(arr[high][1] >= key1))
			high--;
		arr[low][1] =arr[high][1];
		arr[low][0] =arr[high][0];
		while((low<high)&&(arr[low][1] <= key1))
			low++;
		arr[high][1] = arr[low][1];
		arr[high][0] = arr[low][0];
	}
	arr[low][1]=key1;
	arr[low][0]=key0;
	return low;
}
