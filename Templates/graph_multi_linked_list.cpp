//图的邻接多重表的实现
#include<iostream>
#define SIZE 100
using namespace std;
struct edge
{
	int ivex,jvex;
	edge* ilink,jlink;
	int mark;//record if traversed and so on
	int data;//data area, may store its weight or other things
	edge(int i,j,d){
		ivex = i;
		jvex = j;
		data = d;
		ilink = jlink = NULL;
		mark = 0;
	}
};
struct headnode
{
	int id;
	edge* firstedge;
	headnode(int i){
		id = i;
		firstedge = NULL;
	}
};
class graph{
public:
	void setUpGraph();
	void dfs(int start);
	void bfs(int start);
private:
	headnode* heads[SIZE];
};
//read nodes n and the edges,-1 to end
void graph::setUpGraph(){

}