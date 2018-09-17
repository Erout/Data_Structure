#include<iostream>
#include<cmath>
#define size 100000
using namespace std;
void QuickSort(int arr[],int low, int high);
int Partition(int arr[] ,int low, int high);
int main(){
	int n;
	cin>>n;
	int weight[size];
	for(int i = 0; i < n; i++)
		cin>>weight[i];
	QuickSort(weight,0,n-1);
	for(int i = 0; i < n; i++)
		cout<<weight[i]<<" ";
	int one = 0, two = 0;
	while(--n){
		if(one > two){
			two += weight[n];
		}
		else
			one += weight[n];
	}
	if(one > two)
		two += weight[0];
	else
		one += weight[0];
	cout<<abs(one-two)<<endl;

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
void QuickSort(int arr[],int low, int high){
	if(low < high){
		int pivot = Partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}