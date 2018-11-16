#include<iostream>
#include<stack>
#define Size 1000000
using namespace std;
int main(){
	int N;
	cin>>N;
	int count = 1;//not in stack minimun number
	stack<int> st;
	int seq[Size];
	for(int i = 0; i < N; i++){
		cin>>seq[i];
		if(count <= seq[i]){
			while(st.empty()||(st.top() != seq[i])){
				st.push(count);
				count++;
			}
			st.pop();
			continue;
		}
		else{
			if(st.top() == seq[i]){
				st.pop();
				continue;
			}
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
}