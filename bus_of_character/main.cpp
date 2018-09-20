#include<iostream>
#include<string>
#include<cstring>
#define size 20000
#define Debug 0
using namespace std;
void QuickSort(int arr[][4],int low,int high);
int Partition(int arr[][4],int low,int high);
int main(){
	int n;
	int bus[20000][4];//bus[i][0]:id bus[i][1]:width  bus[i][2]:introver bus[i][3]:extrover
	memset(bus,-1,sizeof(bus));
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>bus[i][1];
		bus[i][0] = i;
	}
	QuickSort(bus,0,n-1);
	if(Debug){
		for(int i = 0; i < n; i++){
			cout<<"id"<<bus[i][0]<<" width:"<<bus[i][1]<<endl;
		}
	}
	string s;
	cin>>s;
	int introverSitNumber = 0;//记录in坐到的最后的位置(空)
	int extroverSitNumber = -1;//记录extrover坐到的最前的位置
	for(int i = 0;i < 2*n;i++){
		if(s[i] == '0'){
			//寻找最小宽度的两个都空的位置
			bus[introverSitNumber][2] = 1;
			cout<<bus[introverSitNumber][0]+1<<endl;
			introverSitNumber++;
		}//in
		else{
			//寻找坐了仅一个的宽度最大的位置
			//从introver最大的座位开始寻找
			for(int i = introverSitNumber-1; i > -1; i--){
				if(bus[i][3] == -1){
					bus[i][3] = 1;
					cout<<bus[i][0]+1<<endl;
					break;
				}
			}
		}
	}
}
void QuickSort(int arr[][4],int low,int high){
	if(low < high ){
		int pivot = Partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}
int Partition(int arr[][4],int low,int high){
	int keyWidth = arr[low][1];
	int keyid = arr[low][0];
	while(low < high){
		while((low < high)&&(arr[high][1] >= keyWidth))
			high--;
		arr[low][1] = arr[high][1];
		arr[low][0] = arr[high][0];
		while((low < high)&&(arr[low][1] <= keyWidth))
			low++;
		arr[high][1] = arr[low][1];
		arr[high][0] = arr[low][0];
	}
	arr[low][1] = keyWidth;
	arr[low][0] = keyid;
	return low;
}