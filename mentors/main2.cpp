#include<iostream>
#include<cstring>
#define Size 200002
#define Debug 0
using namespace std;
void QuickSort(int arr[][4],int order, int low, int high);
int Partition(int arr[][4] ,int order, int low, int high);
int main(){
	int programmer[Size][4];
	memset(programmer,0,sizeof(programmer));
	int n,k;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>programmer[i][1];
		programmer[i][0] = i;
	}
	int x,y;
	for(int i = 0; i < k; i++){
		cin>>x>>y;
		if(programmer[x-1][1] > programmer[y-1][1])
			programmer[x-1][2]++;
		else if(programmer[x-1][1] < programmer[y-1][1])
			programmer[y-1][2]++;
	}
	if(Debug){
		cout<<"before"<<endl;
		for(int i = 0; i < n; i++)
			cout<<"id: "<<programmer[i][0]<<" skill:"<<programmer[i][1]<<" quarrel:"<<programmer[i][2]<<" less:"<<programmer[i][3]<<endl;
	}
	int less;
	QuickSort(programmer,1,0,n-1);
		if(Debug){
		cout<<"programmer range based on skill"<<endl;
		for(int i = 0; i < n; i++)
			cout<<"id: "<<programmer[i][0]<<" skill:"<<programmer[i][1]<<" quarrel:"<<programmer[i][2]<<" less:"<<programmer[i][3]<<endl;
	}
	for(int i = 0; i < n; i++) {
		if(i == 0){
			programmer[i][3] = 0;
		}
		else{
			less = i;
			while((less >= 0)&&(programmer[less][1] == programmer[i][1]))
				less--;
			if(less < 0)
				programmer[i][3] = 0;
			else
				programmer[i][3] = less+1;
		}
	}
	QuickSort(programmer,0,0,n-1);
		if(Debug){
		cout<<"programmer range based on id"<<endl;
		for(int i = 0; i < n; i++)
			cout<<"id: "<<programmer[i][0]<<" skill:"<<programmer[i][1]<<" quarrel:"<<programmer[i][2]<<" less:"<<programmer[i][3]<<endl;
	}
	for(int i = 0; i < n;i++)
		cout<<programmer[i][3] -programmer[i][2]<<endl;

} 
void QuickSort(int arr[][4],int order, int low, int high){
	if(low <high){
		int pivot = Partition(arr,order,low,high);
		QuickSort(arr,order,low,pivot-1);
		QuickSort(arr,order,pivot+1,high);
	}
}
int Partition(int arr[][4] ,int order, int low, int high){
	int key0 = arr[low][0];
	int key1 = arr[low][1];
	int key2 = arr[low][2];
	int key3 = arr[low][3];
	int key = arr[low][order];
	while(low < high){
		while((low < high)&&(arr[high][order] >= key))
			high--;
		arr[low][0] = arr[high][0];
		arr[low][1] = arr[high][1];
		arr[low][2] = arr[high][2];
		arr[low][3] = arr[high][3];
		while((low < high) &&(arr[low][order] <= key))
			low++;
		arr[high][0] = arr[low][0];
		arr[high][1] = arr[low][1];
		arr[high][2] = arr[low][2];
		arr[high][3] = arr[low][3];
	}
	//arr[low][order] = key;
	arr[low][0] = key0;
	arr[low][1] = key1;
	arr[low][2] = key2;
	arr[low][3] = key3;
	return low;
}
//排序求出比某个程序员弱的人数，输入时记录和程序员吵架并且比他弱的人数，两者相减得结果