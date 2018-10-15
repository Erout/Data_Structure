#include<iostream>
#include<cstring>
#define size 30002
using namespace std;
void QuickSort(int arr[] ,int low, int high);
int Partition(int arr[],int low,int high);
int main(){
	int n;
	cin>>n;
	string act;
	int boxNum;
	int stak[size];
	memset(stak,0,sizeof(stak));
	int count = 0;
	int NumToMove = 1;
	int pos = 0;
	for(int i = 0; i <2*n; i++){
		cin>>act;
		if(act[0] == 'a'){
			cin>>boxNum;
			stak[pos++] = boxNum;
		}
		else if(act[0] == 'r'){
			if(stak[pos-1] != NumToMove){
				QuickSort(stak,0,pos-1);
				count++;
				pos--;
			}
			else{
				pos--;
			}
			NumToMove++;
		}

	}
	cout<<count;
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
		while((low < high)&&(arr[high] <= key))
			high--;
		arr[low] = arr[high];
		while((low < high)&&(arr[low] >= key))
			low++;
		arr[high] = arr[low];
	}
	arr[low] = key;
	return low;
}