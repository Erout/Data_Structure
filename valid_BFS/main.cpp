//有bug
#include<iostream>
#include<queue>
#define SIZE 200005
using namespace std;
struct connect
{
	int id;
	connect* next;
	connect(int i){
		id = i;
		next = NULL;
	}
};
struct head
{
	int id;
	connect* c;
	int mark;
	int edge;
	int beenSearched;
	head(int i){
		id = i;
		c = NULL;
		mark = 0;
		edge = 0;
		beenSearched = 0;
	}
};
int main(){
	int n,a,b;
	cin>>n;
	head* vertex[SIZE];
	connect* tmp;
	for(int i = 0; i < n-1; i++){
		cin>>a>>b;
		if(vertex[a] == NULL){
			vertex[a] = new head(a);
			vertex[a]->c = new connect(b);
		}
		else{
			tmp = vertex[a]->c;
			while(tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new connect(b);
		}
		if(vertex[b] == NULL){
			vertex[b] = new head(b);
			vertex[b]->c = new connect(a);
		}
		else{
			tmp = vertex[b]->c;
			while(tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new connect(a);
		}
		vertex[a]->edge++;
		vertex[b]->edge++;
	}
	queue<head*> Q;
	int search;
	cin>>search;
	head* father;
	connect* child;
	bool valid = 0;
	Q.push(vertex[search]);
	vertex[search]->beenSearched = 1;
	for(int i = 0; i < n-1; i++){
		valid = 0;
		cin>>search;
		father = Q.front();
		if(father->mark == father->edge){
			Q.pop();
			father = Q.front();
		}
		child = father->c;
		while(child != NULL){
			if(child->id == search && vertex[search]->beenSearched == 0){
				father->mark++;
				vertex[search]->mark++;
				Q.push(vertex[search]);
				vertex[search]->beenSearched = 1;
				valid = 1;
				break;
			}
			child = child->next;
		}
		if(!valid){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}