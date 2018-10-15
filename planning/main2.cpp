#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main(){
	vector<pair<int,int>> fly;
	int n, k, ctemp;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>ctemp;
		fly.push_back(make_pair(ctemp,i));
	}
	sort(fly.begin(),fly.end());
	int total = 0;
	set<pair<int,int>> time;
	for(int i = k; i < n+k; i++)
		time.insert(make_pair(i,0));
	auto it = fly.rbegin();
	auto iter = time.begin();
	//auto iter2 = iter1;
	int tempTime;
	for(it; it != fly.rend(); it++){
		if((*it).second > k){
			iter = time.find(make_pair((*it).second,0));
			if(iter != time.end()){
				//iter2 = iter;
				tempTime = (*iter).first;
				time.insert(make_pair((*iter).first,1));
				time.erase(iter);
				
			}				//找不到
			else{
				iter = time.find(make_pair((*it).second,1));
				while((*iter).second != 0)
					iter++;
				//iter2 = iter;
				tempTime = (*iter).first;
				time.insert(make_pair((*iter).first,1));
				time.erase(iter);
			}	//找到了
		}
		else{
			iter = time.begin();		
			while((*iter).second != 0)
				iter++;
			tempTime = (*iter).first;
			time.insert(make_pair((*iter).first,1));
			time.erase(iter);
		}
		total += (tempTime- (*it).second)*((*it).first);
	}
	cout<<total<<endl;
}