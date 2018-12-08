#include<iostream>
#include<bits/stdc++.h>
//#include<algorithm>
#define SIZE 200005
using namespace std;
int order[SIZE];
struct head
{
	int id;
	vector<int> connect;
	int mark;
	head(int i){
		id = i;
		mark = 0;
	}
};
int main(){
	int check[SIZE];
	head* node[SIZE];
	int n;
	cin>>n;
	int a,b;
	for(int i = 1; i < n; i++){
		cin>>a>>b;
		if(node[a] == NULL){
			node[a] = new head(a);
		}
		if(node[b] == NULL){
			node[b] = new head(b);
		}
		node[a]->connect.push_back(b);
		node[b]->connect.push_back(a);
	}
	for(int i = 0; i < n; i++){
		cin>>check[i];
		order[check[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		auto it = node[i]->connect.begin();
		auto iter = node[i]->connect.end();
		sort(it,iter,[](int x,int y){return order[x] < order[y];});
	}
	//bfs
	int mybfs[SIZE];
	int count = 0;
	mybfs[count++] = 1;
	queue<int> Q;
	Q.push(1);
	node[1]->mark = 1;
	int search;
	while(!Q.empty()){
		search = Q.front();
		Q.pop();
		auto be = node[search]->connect.begin();
		for(be; be != node[search]->connect.end(); be++){
			if(node[*be]->mark == 0){
				mybfs[count++] = *be;
				node[*be]->mark = 1;
				Q.push(*be);
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(mybfs[i] != check[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}