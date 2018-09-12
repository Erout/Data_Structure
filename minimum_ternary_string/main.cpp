#include<iostream>
using namespace std;
int main(){
	string s,record;
	cin>>s;
	for(int i = 0; i < s.size();i++){
		if(s[i] == '1')
			record += '1';
	}
	for(int i = 0; i < s.size();i++){
		if(s[i] == '0')
			cout<<"0";
		else if(s[i] == '2'){
			if(!record.empty()){
				cout<<record;
				record.clear(); 				
			}
			cout<<"2";
		}
	}
	if(!record.empty())
		cout<<record;
}
/*
题解：贪心  因为只有0和2位置不能交换，所以对于1来说没有影响，
先把所有1的个数记录下来。然后从前往后遍历，遇见0就输出0，遇见1就跳过，
遇见2把全部1输出，再输出2，然后后面的遇见0就输出0，遇见2输出2，遇见1跳过。
*/