#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,b;
	vector<pair<int,int>> V;
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		V.push_back(make_pair(a,b));
	}
	sort(V.begin(),V.end());
	int ans = 0;
	auto iter = V.begin();
	auto itt = V.begin();
	for(iter; iter != V.end(); iter++){
		for(itt = V.begin(); itt != iter; itt++){
			if((*itt).second > (*iter).second){
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}