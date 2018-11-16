#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define Size 10000
using namespace std;
struct node
{
	vector<node*> connect;
	node* parent;
	bool cat;
	int consecutive;
	int color;
	node(){
		cat = 0;
		parent = NULL;
		consecutive = 0;
		color = 0;
	}
};
int main(){
	node* vertices[Size];
	memset(vertices,0,sizeof(vertices));
	int n,m;
	cin>>n>>m;
	int haveCat;
	for(int i = 1; i <= n; i++){
		vertices[i]  = new node;
		cin>>haveCat;
		if(haveCat == 1){
			vertices[i]->cat = 1;
		}
	}
	int x,y;
	for(int i = 0; i < n-1; i++){
		cin>>x>>y;
		vertices[x]->connect.push_back(vertices[y]);
		vertices[y]->connect.push_back(vertices[x]);
	}
	node* home = vertices[1];
	queue<node*> search;
	search.push(home);
	int restaurant = 0;
	while(!search.empty()){
		node* seek = search.front();
		search.pop();
		seek->color = 1;
		if(seek->cat){
			if(seek->parent != NULL)
				seek->consecutive = seek->parent->consecutive + 1;
			else
				seek->consecutive = 1;
		}
		else{
			seek->consecutive = 0;
		}
		if(seek->consecutive > m)
			continue;
		if(seek->connect.size()==1 && seek != home)
			restaurant++;
		else{
			for(auto it = seek->connect.begin(); it != seek->connect.end();it++){
				if((*it)->color == 0){
					(*it)->parent = seek;
					search.push(*it);
				}
			}
		}
	}
	cout<<restaurant<<endl;
}