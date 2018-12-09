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
	G.recursiveDFS(3);
	G.printDFS();
	G.RecursivePrintTree(3,0,G.getDFSTree());

	G.nonRecursiveDFS2(3);
	G.RecursivePrintTree(3,0,G.getDFSTree());

	G.nonRecursiveDFS(3);
	G.RecursivePrintTree(3,0,G.getDFSTree());
	
}
