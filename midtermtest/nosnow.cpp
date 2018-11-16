#include<iostream>
#include<vector>
#define Size 1000000
using namespace std;
int main(){
	int N;
	//long long snow[Size];
	vector<long long> snow;
	long long temperature[Size];
	cin>>N;
	int count = 0;//formest snow left 
	int melt = 0;
	int first = 1;
	long long sn;
	for(int i = 0; i < N; i++){
		//cin>>snow[i];
		cin>>sn;
		snow.push_back(sn);
	}
	//snow.erase();
	auto iter = snow.begin();
	for(int i = 0; i < N; i++){
		cin>>temperature[i];
		iter++;
		melt = 0;
		/*
		for(int j = count; j <= i; j++){
			if(snow[j] > 0){
				if(snow[j] >= temperature[i])
					melt += temperature[i];
				else
					melt += snow[j];
				snow[j] -= temperature[i];
			}
		}*/
		auto it = snow.begin();
		while(it != iter){
			if(*it > 0){
				if(*it >= temperature[i])
					melt += temperature[i];
				else
					melt += (*it);
				(*it) -= temperature[i];
			}
			it++;
			if(*it < 0)
				snow.erase(it);
		}
		if(first){
			cout<<melt;
			first = 0;
		}
		else{
			cout<<" "<<melt;
		}
		while(snow[count] <= 0)
			count++;
	}
	cout<<endl;
}