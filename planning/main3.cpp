#include<iostream>
#include<set>
#define size 60003
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	set<pair<int,int>> fly;
	bool position[size];
	int temp;
	for(int i = 0; i < n; i++){
		cin>>temp;
		fly.insert(make_pair(temp,i));
	}
	long long total = 0;
	int startPos;
	auto it = fly.rbegin();
	for(it; it != fly.rend(); it++){
		if((*it).second > k){
			startPos = (*it).second;
		}
		else{
			startPos = k;
		}
		while(position[startPos] != 0)
			startPos++;
		position[startPos] = 1;
		total +=(startPos-(*it).second)*(*it).first;
	}
	cout<<total<<endl;
}