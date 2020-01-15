#include<iostream>
#include "graph.hpp"
using namespace std;
void welcome();
int main(){
	graph G;
	G.setUpGraph();
	int act,vertex;
	welcome();
	cin>>act;
	while(act != -1){
		cout<<"                             ";
		cout<<"请输入开始遍历的节点序号"<<endl;
		cin>>vertex;
		switch(act){
			case 1:
				G.nonRecursiveDFS(vertex);
			break;
			case 2:
				G.BFS(vertex);
			break;
			case 3:
				G.nonRecursiveDFS2(vertex);
			break;
			case 4:
				G.BFS2(vertex);
			break;
		}
		welcome();
		cin>>act;
	}
	cout<<"                             ";
	cout<<"感谢您的使用!"<<endl;
}
void welcome(){
	cout<<"                         ";
	cout<<"-------------------------------------------"<<endl;
	cout<<"                             ";
	cout<<"请输入序号以进行相应操作"<<endl;
	cout<<endl;
	cout<<"                             ";
	cout<<"1、深度优先搜索邻接多重表"<<endl;
	cout<<"                             ";
	cout<<"2、广度优先搜索邻接多重表"<<endl;
	cout<<"                             ";
	cout<<"3、深度优先搜索邻接表"<<endl;
	cout<<"                             ";
	cout<<"4、广度优先搜索邻接表"<<endl;
	cout<<endl;
	cout<<"                             ";
	cout<<"输入-1退出程序"<<endl;
	cout<<"                         ";
	cout<<"-------------------------------------------"<<endl;

}