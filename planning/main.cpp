#include<iostream>
#include<cstring>
#define Debug 0
#define size 300002
using namespace std;
int Partition(int arr[][2],int low, int high);
void Sort(int arr[][2], int low, int high);
int main(){
	int n, k;
	cin>>n>>k;
	int flight[size][2];
	//[0]cost [1]origin departure time
	for(int i = 1; i <= n; i++){
		cin>>flight[i][0];
		flight[i][1] = i;
	}
	Sort(flight,1,n);
	int total = 0;
	int time[size *2];
	int tempT;
	memset(time,0,sizeof(time));
	for(int i = 1; i <= n; i++){
		if(flight[i][1] > k)
			tempT = flight[i][1];
		else
			tempT = k+1;
		while((time[tempT] == 1)||(tempT < flight[i][1]))
			tempT++;
		time[tempT] = 1;
		total += flight[i][0]*(tempT-flight[i][1]);
		if(Debug)
			cout<<"tempT:"<<tempT<<" total"<<total<<endl;
	}
	cout<<total<<endl;
} 
int Partition(int arr[][2],int low, int high){
	int key1 = arr[low][0];
	int key2 = arr[low][1];
	while(low < high){
		while((arr[high][0] <= key1)&&(low<high))
			high--;
		arr[low][0] = arr[high][0];
		arr[low][1] = arr[high][1];
		while((arr[low][0] >= key1)&&(low<high))
			low++;
		arr[high][0] = arr[low][0];
		arr[high][1] = arr[low][1];
	}
	arr[low][0] = key1;
	arr[low][1] = key2;
	return low;
}
void Sort(int arr[][2], int low, int high){
	if(low < high){
		int pivot = Partition(arr,low,high);
		Sort(arr,low, pivot-1);
		Sort(arr,pivot+1,high);
	}
}