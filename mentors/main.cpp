#include<iostream>
#include<cstdlib>
#include<cstring>
#define Size 200003
#define Debug 1
using namespace std;
void QuickSort(int arr[][3],int order, int low, int high);
int Partition(int arr[][3] ,int order, int low, int high);
bool InQuarrel(int quarrel[][3],int a,int b,int range);
int main(){
	int n,k;
	int programmer[Size][3];//0 for id, 1 for skill, 2 for number can be mentor
	int quarrel[Size][3];//pair int qurrel,3 for blank,
	int q = 0;
	memset(programmer,0,sizeof(programmer));
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>programmer[i][1];
		programmer[i][0] = i;
	}
	int x,y;
	for(int i = 0; i < k; i++){
		cin>>x>>y;
		if(x <= y){
			quarrel[q][0] = x-1;
			quarrel[q][1] = y-1;
		}
		else{
			quarrel[q][0] = y-1;
			quarrel[q][1] = x-1;
		}
		q++;
	}
	if(Debug){
		cout<<"before sort"<<endl;
		for(int i = 0; i < k;i++)
			cout<<"quarrel: "<<quarrel[i][0]<<" "<<quarrel[i][1]<<endl;
	}
	//排序吵架的对，先小后大
	QuickSort(quarrel,0,0,k-1);
	if(Debug){
		cout<<"after sort"<<endl;
		for(int i = 0; i < k;i++)
			cout<<"quarrel: "<<quarrel[i][0]<<" "<<quarrel[i][1]<<endl;
	}
	//先按skill大小排序，算得mentor值
	QuickSort(programmer,1,0,n-1);
	if(Debug){
		cout<<"programmer range based on skill"<<endl;
		for(int i = 0; i < n; i++)
			cout<<"id: "<<programmer[i][0]<<" skill:"<<programmer[i][1]<<endl;
	}
	//programmer[i]skill > programmer[j]skill,decide whether quarrel
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if((!InQuarrel(quarrel,programmer[i][0],programmer[j][0],k-1))&&(programmer[i][1] > programmer[j][1]))
				programmer[i][2]++;
		}
	}
	//再按照id大小排序 输出
	QuickSort(programmer,0,0,n-1);
	if(Debug){
		cout<<"programmer range based on id"<<endl;
		for(int i = 0; i < n; i++)
			cout<<"id: "<<programmer[i][0]<<" skill:"<<programmer[i][1]<<" mentors:"<<programmer[i][2]<<endl;
	}
	for(int i = 0; i < n; i++)
		cout<<programmer[i][2]<<endl;
}
void QuickSort(int arr[][3],int order, int low, int high){
	if(low <high){
		int pivot = Partition(arr,order,low,high);
		QuickSort(arr,order,low,pivot-1);
		QuickSort(arr,order,pivot+1,high);
	}
}
int Partition(int arr[][3] ,int order, int low, int high){
	int key0 = arr[low][0];
	int key1 = arr[low][1];
	int key2 = arr[low][2];
	int key = arr[low][order];
	while(low < high){
		while((low < high)&&(arr[high][order] >= key))
			high--;
		arr[low][0] = arr[high][0];
		arr[low][1] = arr[high][1];
		arr[low][2] = arr[high][2];
		while((low < high) &&(arr[low][order] <= key))
			low++;
		arr[high][0] = arr[low][0];
		arr[high][1] = arr[low][1];
		arr[high][2] = arr[low][2];
	}
	//arr[low][order] = key;
	arr[low][0] = key0;
	arr[low][1] = key1;
	arr[low][2] = key2;
	return low;
}
bool InQuarrel(int quarrel[][3],int a,int b,int range){
	int big,small;
	if(a < b){
		small = a;
		big = b;
	}
	else{
		small = b;
		big = a;
	}
	int low = 0, high = range;
	int mid;
	int position = -1;
	while(low <= high){
		mid = (low+high)/2;
		if(quarrel[mid][0] == small){
			position = mid;
			break;
		}
		else if(quarrel[mid][0] > small)
			high = mid -1;
		else{
			low = mid + 1;
		}
	}
	int moveFront = position;
	while((quarrel[moveFront][0] == small)&&(moveFront > -1)){
		if(quarrel[moveFront][1] == big)
			return true;
		moveFront--;
	}
	int moveBack = position;
	while((quarrel[moveBack][0] == small)&&(moveBack < range)&&(moveBack > -1)){
		if(quarrel[moveBack][1] == big)
			return true;
		moveBack++;
	}
	if(Debug)
		cout<<a<<" and "<<b<<" not in quarrel"<<endl;
	return false;
}
//Inquarrel 函数检查