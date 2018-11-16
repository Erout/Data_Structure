#include<iostream>
#include<cstring>
using namespace std;
int count = 0;
bool change(string s1,string s2);
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<change(s1,s2)<<endl;
}
bool change(string s1,string s2){
	cout<<s1<<" "<<s2<<endl;
	count++;
	cout<<count<<endl;
	if(count > 5)
		return false;
	if(s1.size() != s2.size())
		return false;
	if(s1 == s2)
		return true;
	int arr1[130];
	int arr2[130];
	memset(arr1,0,sizeof(arr1));
	memset(arr2,0,sizeof(arr2));
	for(int i = 0; i < s1.size();i++){
		arr1[s1[i]]++;
		arr2[s2[i]]++;
	}
	for(int i = 0; i < 130; i++){
		if(arr1[i] != arr2[i])
			return false;
	}
	if(s1.size() <= 3)
		return true;
	int len = s1.size();
	for(int i = 1; i < len;i++){
		if((change(s1.substr(0,i),s2.substr(0,i))&&change(s1.substr(i,len-i),s2.substr(i,len-i)))||
			(change(s1.substr(0,i),s2.substr(len-i-1,i)) && change(s1.substr(len-i-1,len-i),s2.substr(0,len-i))))
			return true;
	}
	return false;
}
