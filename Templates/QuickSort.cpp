#include<iostream>
#define size 100
using namespace std;
void QuickSort(int arr[] ,int low, int high);
int Partition(int arr[],int low,int high);
int main(){
	int n;
	int arr[size];
	cout<<"请输入规模"<<endl;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	//sort
	QuickSort(arr,0,n-1);
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

}
void QuickSort(int arr[],int low,int high){
	if(low < high ){
		int pivot = Partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}
int Partition(int arr[],int low,int high){
	int key = arr[low];
	while(low < high){
		while((low < high)&&(arr[high] >= key))
			high--;
		arr[low] = arr[high];
		while((low < high)&&(arr[low] <= key))
			low++;
		arr[high] = arr[low];
	}
	arr[low] = key;
	return low;
}