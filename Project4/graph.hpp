#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#define SIZE 35
using namespace std;
struct edge
{
	int ivex,jvex;
	edge* ilink, *jlink;
	int mark;
	edge(int i, int j){
		ivex = i;
		jvex = j;
		mark = 0;
		ilink = jlink = NULL;
	}
};
struct headnode
{
	int id;
	string name;
	edge* firstedge;
	int mark;
	headnode(int id_,string name_){
		id = id_;
		name = name_;
		firstedge = NULL;
		mark = 0;
	}
};
struct AcityNode
{
	int id;
	string name;
	AcityNode* next;
	AcityNode(int id_,string name_){
		id = id_;
		name = name_;
		next = NULL;
	}
};
struct Acity
{
	int id;
	string name;
	AcityNode* firstNode;
	Acity(int id_,string name_){
		id = id_;
		name = name_;
		firstNode = NULL;
	}
};

class graph{
public:
	graph();
	~graph();
	void setUpGraph();//生成两种储存方式的树，通过读取文件
	void recursiveDFS();
	void nonRecursiveDFS();
	void BFS(int vertex);
	void clearMark();
	void addEdgeToMulLink(int a, int b, headnode* array[]);
private:
	Acity* city[SIZE];//第三题的邻接表
	headnode* city_mul[SIZE];//第一题的邻接多重表
	headnode* DFSTree[SIZE];//深度优先生成树
	headnode* BFSTree[SIZE];//广度优先生成树
	string cityname[SIZE];
};