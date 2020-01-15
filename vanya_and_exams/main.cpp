#include<iostream>
#include<algorithm>
#define SIZE 100005
using namespace std;
void mysort(int low,int high, long long a[],long long b[]);
int partition(int low, int high, long long a[],long long b[]);
int main(){
	int n,r,avg;
	cin>>n>>r>>avg;
	long long a[SIZE], b[SIZE];
	long long expectTotal = avg*n;
	long long totalNow = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i];
		totalNow += a[i];
	}
	mysort(0,n-1,a,b);
	long long count = 0;
	long long order = 0;
	while(totalNow < expectTotal){
		if(expectTotal-totalNow >= r-a[order]){
			count += b[order]*(r-a[order]);
			totalNow += (r-a[order]);
		}
		else{
			count += b[order]*(expectTotal-totalNow);
			totalNow = expectTotal;
		}
		order++;
	}
	cout<<count<<endl;
}
void mysort(int low, int high, long long a[], long long b[]){
	int pivot;
	if(low < high){
		pivot = partition(low, high,a,b);
		mysort(low,pivot-1,a,b);
		mysort(pivot+1,high,a,b);
	}
}
int partition(int low, int high, long long a[], long long b[]){
	int akey = a[low];
	int bkey = b[low];
	while(low < high){
		while(low < high && b[high] >= bkey)
			high--;
		a[low] = a[high];
		b[low] = b[high];
		while(low < high && b[low] <= bkey)
			low++;
		a[high] = a[low];
		b[high] = b[low];
	}
	a[low] = akey;
	b[low] = bkey;
	return low;
}