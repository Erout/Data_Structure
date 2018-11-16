#include<iostream>
#include<cstdio>
#include<cstring>
#define Size 1000000
using namespace std;
struct node
{
	int edge[Size];//edge[0] for path to parent
	int val;
	node* parent;
	node* next[Size];
	int child;
	node(int v){
		val = v;
		parent = NULL;
		memset(edge,0,Size);
		memset(next,0,Size);
		child = 0;
	}
};
int main(){
	int n;
	int temp;
	node* root = new node(1);
	node* n,search;
	queue<node*> Q;
	int add = 0;
	int count = 2;
	for(int i = 0; i < n; i++){
		search = root;
		scanf("%d",&temp);
		n = new node(count);
		count++;
		while(!add && !Q.empty()){
			search = Q.top();
			Q.pop();
			if(search->val == temp){
				search[child++] = n;
				n->parent = search;
				add = 1;
			}
			for(int j = 0; j < search->child; j++){
				Q.push(search->next[j]);
			}
		}
	}
}