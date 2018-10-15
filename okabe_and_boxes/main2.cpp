#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	string act;
	int boxNum;
	int count = 0;
	int NumToMove = 1;
	vector<int> mystack;
	for(int i = 0; i < 2*n; i++){
		cin>>act;
		if(act[0] == 'a'){
			cin>>boxNum;
			mystack.insert(mystack.begin(),boxNum);
		}
		else if(act[0] == 'r'){
			if(*mystack.begin() == NumToMove)
				mystack.erase(mystack.begin());
			else{
				sort(mystack.begin(),mystack.end());
				mystack.erase(mystack.begin());
				count++;
			}
			NumToMove++;
		}
	}
	cout<<count<<endl;
}