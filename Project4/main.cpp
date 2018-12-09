#include<iostream>
#include "graph.hpp"
using namespace std;
int main(){
	graph G;
	G.setUpGraph();
	/*
	G.BFS(15);
	G.RecursivePrintTree(15,0,G.getBFSTree());
	G.BFS2(15);
	G.RecursivePrintTree(15,0,G.getBFSTree());
	*/
	G.RecursiveDFS(16);

	G.nonRecursiveDFS2(16);
	//G.RecursivePrintTree(3,0,G.getDFSTree());

	G.nonRecursiveDFS(16);
	G.nonRecursiveDFS(14);
	//G.RecursivePrintTree(3,0,G.getDFSTree());
	
}
