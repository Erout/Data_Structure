#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;
bool substring(string t,string s);
int main(){
	//cout<<substring("qwt","qwt")<<endl;
	int n;
	cin>>n;
	vector<pair<int,string> > all;
	string temp;
	for(int i = 0; i < n; i++){
		cin>>temp;
		all.push_back(pair<int, string>(temp.size(),temp));
	}
	sort(all.begin(),all.end());

	auto iter = all.begin();
	auto it = iter;
	it++;
	for(it; it != all.end();it++){
		if(!substring((*iter).second,(*it).second)){
			cout<<"NO"<<endl;
			return 0;
		}
		iter++;
	}
	cout<<"YES"<<endl;
	for(iter = all.begin();iter != all.end();iter++){
		cout<<(*iter).second<<endl;
	}
}
bool substring(string t,string s){
	int k;
	for(int i = 0; i <= (s.size()-t.size());i++){
		if(s[i] == t[0]){
			for(int j = 0; j < t.size();j++){
				k = i;
				while((t[j] == s[k])&&(j < t.size())){
					j++;
					k++;
				}
				if(j == t.size())
					return true;
			}
		}

	}
	return false;
}