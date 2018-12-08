#include<iostream>
#define SIZE 100003
using namespace std;
struct edge
{
	int mark;
	int ivex;
	edge* ilink;
	int jvex;
	edge* jlink;
	int weight;
	edge(int w,int i,int j){
		weight = w;
		ivex = i;
		jvex = j;
		ilink = NULL;
		jlink = NULL;
		mark = 0;
	}
};
struct headnode
{
	edge* firstedge;
	int id;
	headnode(int x){
		id = x;
		firstedge = NULL;
	}
};
int dfs(headnode* graph[],int v);
int main(){
	int n;
	int x,y,w;
	headnode* heads[SIZE];
	edge* etemp;
	bool isadd = 0;
	cin>>n;
	int totalWei = 0;
	for(int i = 1; i < n; i++){
		cin>>x>>y>>w;
		totalWei += w;
		etemp = new edge(w,x,y);
		if(heads[x] == NULL){
			heads[x] = new headnode(x);
			heads[x]->firstedge = etemp;
		}
		else{
			edge* add = heads[x]->firstedge;
			isadd = 0;
			while(!isadd){
				if(add->ivex == x){
					if(add->ilink == NULL){
						add->ilink = etemp;
						isadd = 1;
					}
					else
						add = add->ilink;
				}
				else if(add->jvex == x){
					if(add->jlink == NULL){
						add->jlink = etemp;
						isadd = 1;
					}
					else
						add = add->jlink;
				}
			}
		}
		if(heads[y] == NULL){
			heads[y] = new headnode(y);
			heads[y]->firstedge = etemp;
		}
		else{
			edge* add = heads[y]->firstedge;
			isadd = 0;
			while(!isadd){
				if(add->ivex == y){
					if(add->ilink == NULL){
						add->ilink = etemp;
						isadd = 1;
					}
					else
						add = add->ilink;
				}
				else if(add->jvex == y){
					if(add->jlink == NULL){
						add->jlink = etemp;
						isadd = 1;
					}
					else
						add = add->jlink;
				}
			}
		}
	}
	/*for(int i = 1; i <= n; i++){
		edge* et = heads[i]->firstedge;
		cout<<"head"<<i<<" connected edges:";
		while(et != NULL){
			cout<<"->"<<"ivex:"<<et->ivex<<" "<<et->ilink<<" jvex:"<<et->jvex<<" "<<et->jlink;
			if(et->ivex == i){
				et = et->ilink;
			}
			else if(et->jvex == i){
				 et = et->jlink;
			}
		}
		cout<<endl;
	}*/
	//cout<<dfs(heads,1);
	//cout<<totalWei<<endl;
	cout<<(totalWei*2 - dfs(heads,1))<<endl;
}
int dfs(headnode* graph[],int v){
	//cout<<"dfsing"<<v<<endl;
	edge* e = graph[v]->firstedge;
	int maxValue = 0;
	while(e != NULL){
		if(e->mark == 0){
			e->mark = 1;
			if(e->ivex == v){
				maxValue = max(maxValue,e->weight+dfs(graph,e->jvex));
			}
			else if(e->jvex == v){
				maxValue = max(maxValue,e->weight+dfs(graph,e->ivex));
			}
		}
		if(e->ivex == v){
			e = e->ilink;
		}
		else if(e->jvex == v){
			e = e->jlink;
		}
	}
	return maxValue;
	
}
int max(int a,int b){
	return (a>b?a:b);
}