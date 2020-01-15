#include "graph.hpp"
#define Debug 0
graph::graph(){
	for(int i = 0; i < SIZE; i++){
		city[i] = NULL;
		city_mul[i] = NULL;
		DFSTree[i] = NULL;
		BFSTree[i] = NULL;
	}
}
graph::~graph(){
	for(int i = 0; i < SIZE; i++){
		if(city[i] != NULL)
			delete city[i];
		if(DFSTree[i] != NULL)
			delete DFSTree[i];
		if(BFSTree[i] != NULL)
			delete BFSTree[i];
		if(city_mul[i] != NULL)
			delete city_mul[i];
		city_mul[i] = NULL;
		city[i] = NULL;
		DFSTree[i] = BFSTree[i] = NULL;
	}
}
void graph::clearFormerBFS(){
	for(int i = 0; i < SIZE; i++){
		if(BFSTree[i] != NULL){
			delete BFSTree[i];
			BFSTree[i] = NULL;
		}
	}
}
void graph::clearFormerDFS(){
	for(int i = 0; i < SIZE; i++){
		if(DFSTree[i] != NULL){
			delete DFSTree[i];
			DFSTree[i] = NULL;
		}
	}
}
void graph::clearMark(){
	for(int i = 0; i < SIZE; i++){
		if(city[i] != NULL)
			city[i]->mark = 0;
		if(city_mul[i] != NULL)
			city_mul[i]->mark = 0;
	}
}
void graph::setUpGraph(){
	//读城市号码对应的名称
	ifstream fname("city_and_number.txt");
	string tempName;
	int tempId;
	while(!fname.eof()){
		fname>>tempId;
		fname>>tempName;
		cityname[tempId] = tempName;
	}
	ifstream fin("city_connect.in");
	int a,b;
	while(!fin.eof()){
		fin>>a;
		fin>>b;
		//先建立邻接表		
		AcityNode* tmpAdd;
		if(city[a] == NULL){
			city[a] = new Acity(a,cityname[a]);
			city[a]->firstNode = new AcityNode(b,cityname[b]);
		}
		else{
			tmpAdd = city[a]->firstNode;
			while(tmpAdd->next != NULL){
				tmpAdd = tmpAdd->next;
			}
			tmpAdd->next = new AcityNode(b,cityname[b]);
		}
		if(city[b] == NULL){
			city[b] = new Acity(b,cityname[b]);
			city[b]->firstNode = new AcityNode(a,cityname[a]);
		}
		else{
			tmpAdd = city[b]->firstNode;
			while(tmpAdd->next != NULL){
				tmpAdd = tmpAdd->next;
			}
			tmpAdd->next = new AcityNode(a,cityname[a]);
		}
		//cout<<"over for link list"<<endl;
		//再建立邻接多重表
		
		edge* tmp,*addEdge;
		bool add = 0;
		addEdge = new edge(a,b);
		if(city_mul[a] == NULL){
			//cout<<"here a"<<endl;
			city_mul[a] = new headnode(a,cityname[a]);
			city_mul[a]->firstedge = addEdge;
		}
		else{
			add = 0;
			tmp = city_mul[a]->firstedge;
			while(!add){
				//cout<<tmp->ivex<<" "<<tmp->ilink<<" "<<tmp->jvex<<" "<<tmp->jlink<<endl;
				if(tmp->ivex == a){
					if(tmp->ilink != NULL){
						tmp = tmp->ilink;
					}
					else{
						tmp->ilink = addEdge;
						add = 1;
					}
				}
				else if(tmp->jvex == a){
					if(tmp->jlink != NULL)
						tmp = tmp->jlink;
					else{
						tmp->jlink = addEdge;
						add = 1;
					}
				}
			}
		}
		if(city_mul[b] == NULL){
			//cout<<"here b"<<endl;
			city_mul[b] = new headnode(b,cityname[b]);
			city_mul[b]->firstedge = addEdge;
		}
		else{
			add = 0;
			tmp = city_mul[b]->firstedge;
			while(!add){
				if(tmp->ivex == b){
					if(tmp->ilink != NULL)
						tmp = tmp->ilink;
					else{
						tmp->ilink = addEdge;
						add = 1;
					}
				}
				else if(tmp->jvex == b){
					if(tmp->jlink != NULL)
						tmp = tmp->jlink;
					else{
						tmp->jlink = addEdge;
						add = 1;
					}
				}
			}
		}
	}
	//cout<<"over"<<endl;
	if(Debug){
		cout<<"邻接表的连接情况"<<endl;
		for(int i = 1; i < 26; i++){
			cout<<i<<cityname[i]<<"->";
			AcityNode* checknode;
			if(city[i] != NULL){
				checknode = city[i]->firstNode;
				while(checknode != NULL){
					cout<<checknode->id<<checknode->name<<"->";
					checknode = checknode->next;
				}				
			}

			cout<<endl;
		}
		
		cout<<"多重邻接表的连接情况"<<endl;
		for(int i = 1; i < 26; i++){
			cout<<i<<cityname[i]<<"->";
			edge* checkedge;
			if(city_mul[i] != NULL){
				checkedge = city_mul[i]->firstedge;
				while(checkedge != NULL){
					cout<<"ivex"<<checkedge->ivex<<" jvex"<<checkedge->jvex<<"->";
					if(checkedge->ivex == i){
						checkedge = checkedge->ilink;
					}
					else if(checkedge->jvex == i){
						checkedge = checkedge->jlink;
					}
				}				
			}
			cout<<endl;
		}
	}

}
//邻接多重表广度优先搜索,树也使用邻接表存储
void graph::BFS(int vertex){
	clearFormerBFS();
	clearMark();
	int visitOrder[SIZE];
	int order = 0;
	int edgeSet[SIZE*SIZE][2];
	int edgecount = 0;
	queue<headnode*> Q;
	Q.push(city_mul[vertex]);
	headnode* serach;
	edge* tempEdge;
	while(!Q.empty()){
		serach = Q.front();
		Q.pop();
		visitOrder[order++] = serach->id;
		serach->mark = 1;
		tempEdge = serach->firstedge;
		while(tempEdge != NULL){
			if(tempEdge->ivex == serach->id){
				//若和正在遍历的点相连的节点未被遍历，那么则将它加到遍历队伍之中
				if(city_mul[tempEdge->jvex]->mark != 1){
					city_mul[tempEdge->jvex]->mark = 1;
					edgeSet[edgecount][0] = tempEdge->ivex;
					edgeSet[edgecount][1] = tempEdge->jvex;
					edgecount++;
					addEdgeToTree(tempEdge->ivex,tempEdge->jvex,BFSTree);
					Q.push(city_mul[tempEdge->jvex]);
				}
				tempEdge = tempEdge->ilink;
			}
			else if(tempEdge->jvex == serach->id){
				if(city_mul[tempEdge->ivex]->mark != 1){
					city_mul[tempEdge->ivex]->mark = 1;
					edgeSet[edgecount][0] = tempEdge->jvex;
					edgeSet[edgecount][1] = tempEdge->ivex;
					edgecount++;
					addEdgeToTree(tempEdge->jvex,tempEdge->ivex,BFSTree);
					Q.push(city_mul[tempEdge->ivex]);
				}
				tempEdge = tempEdge->jlink;
			}
		}
	}
	cout<<"                             ";
	cout<<"以下是节点访问序列"<<endl;
	for(int i = 0; i < 26; i++){
		if(BFSTree[i] == NULL){
			BFSTree[i] = new Acity(i,cityname[i]);
		}
	}
	for(int i = 0; i < order; i++){
		cout<<visitOrder[i]<<" ";
	}
	cout<<endl;
	cout<<"                             ";
	cout<<"以下是生成树的边集"<<endl;
	for(int i = 0; i < edgecount; i++){
		cout<<edgeSet[i][0]<<"->"<<edgeSet[i][1]<<" ,";
	}
	cout<<endl;
	cout<<"                             ";
	cout<<"以下是生成树"<<endl;
	RecursivePrintTree(vertex,0,BFSTree);
}
//树边，为有向边，存出边邻接表
void graph::addEdgeToTree(int a, int b, Acity* array[]){
	if(array[a] == NULL){
		array[a] = new Acity(a,cityname[a]);
		array[a]->firstNode = new AcityNode(b,cityname[b]);
	}
	else{
		AcityNode* temp = array[a]->firstNode;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new AcityNode(b,cityname[b]);
	}
}
void graph::RecursivePrintTree(int pr, int offset,Acity* array[]){
	AcityNode* n;
	n = array[pr]->firstNode;
	for(int i = 0; i < (offset-1)*5; i++)
		cout<<" ";
	if(offset){
		cout<<'+';
		for(int i = 0; i < 4; i++)
			cout<<"-";		
	}
	cout<<array[pr]->id<<array[pr]->name<<endl;
	while(n != NULL){
		RecursivePrintTree(n->id,offset+1,array);
		n = n->next;
	}
}
//邻接表广度优先搜索，树使用邻接表存储
void graph::BFS2(int vertex){
	clearFormerBFS();
	clearMark();
	queue<int> Q;
	Q.push(vertex);
	int serach;
	AcityNode* n;
	while(!Q.empty()){
		serach = Q.front();
		Q.pop();
		city[serach]->mark = 1;
		n = city[serach]->firstNode;
		while(n != NULL){
			if(city[n->id]->mark != 1){
				city[n->id]->mark = 1;
				Q.push(n->id);
				addEdgeToTree(serach,n->id,BFSTree);
			}
			n = n->next;
		}
	}
	for(int i = 0; i < 26; i++){
		if(BFSTree[i] == NULL){
			BFSTree[i] = new Acity(i,cityname[i]);
		}
	}
	cout<<"                             ";
	cout<<"以下是生成树"<<endl;
	RecursivePrintTree(vertex,0,BFSTree);
}
//邻接表DFS
void graph::recursiveVisit(int vertex){
	AcityNode* n;
	if(city[vertex]->mark != 2){
		city[vertex]->mark  = 2;
		n = city[vertex]->firstNode;
		while(n != NULL){
			if(city[n->id]->mark != 2){
				addEdgeToTree(vertex,n->id,DFSTree);
				recursiveVisit(n->id);
			}
			n = n->next;
		}
	}
}
void graph::RecursiveDFS(int vertex){
	recursiveVisit(vertex);
	for(int i = 0; i < 26; i++){
		if(DFSTree[i] == NULL){
			DFSTree[i] = new Acity(i,cityname[i]);
		}
	}
	RecursivePrintTree(vertex,0,DFSTree);
}
//邻接表的非递归DFS
void graph::nonRecursiveDFS2(int vertex){
	clearFormerDFS();
	clearMark();
	stack<int> S;
	S.push(vertex);
	int serach;
	AcityNode* n;
	while(!S.empty()){
		serach = S.top();
		city[serach]->mark = 3;
		n = city[serach]->firstNode;
		while(n != NULL && city[n->id]->mark == 3){
			n = n->next;
		}
		if(n == NULL){
			S.pop();
			continue;
		}
		else{
			addEdgeToTree(serach,n->id,DFSTree);
			city[n->id]->mark = 3;
			S.push(n->id);
		}
	}
	for(int i = 0; i < 26; i++){
		if(DFSTree[i] == NULL){
			DFSTree[i] = new Acity(i,cityname[i]);
		}
	}
	cout<<"                             ";
	cout<<"以下是生成树"<<endl;
	RecursivePrintTree(vertex,0,DFSTree); 
}
void graph::nonRecursiveDFS(int vertex){
	clearFormerDFS();
	clearMark();
	int visitOrder[SIZE];
	int order = 0;
	int edgeSet[SIZE*SIZE][2];
	int edgecount = 0;
	stack<int> S;
	S.push(vertex);
	int serach;
	edge* e;
	bool findnext = 0;
	visitOrder[order++] = vertex;
	while(!S.empty()){
		serach = S.top();
		city_mul[serach]->mark = 3;
		e = city_mul[serach]->firstedge;
		findnext = 0;
		while(e != NULL && !findnext){
			if(e->ivex == serach){
				if(city_mul[e->jvex]->mark != 3){
					edgeSet[edgecount][0] = serach;
					edgeSet[edgecount][1] = e->jvex;
					edgecount++;
					addEdgeToTree(serach,e->jvex,DFSTree);
					city_mul[e->jvex]->mark = 3;
					S.push(e->jvex);
					visitOrder[order++] = e->jvex;
					findnext = 1;
				}
				else
					e = e->ilink;
			}
			else if(e->jvex == serach){
				if(city_mul[e->ivex]->mark != 3){
					edgeSet[edgecount][0] = serach;
					edgeSet[edgecount][1] = e->ivex;
					edgecount++;
					addEdgeToTree(serach,e->ivex,DFSTree);
					city_mul[e->ivex]->mark = 3;
					S.push(e->ivex);
					visitOrder[order++] = e->ivex;
					findnext = 1;
				}
				else
					e = e->jlink;
			}			
		}
		if(!findnext){
			S.pop();
		}
	}
	for(int i = 0; i < 26; i++){
		if(DFSTree[i] == NULL){
			DFSTree[i]  = new Acity(i,cityname[i]);
		}
	}
	cout<<"                             ";
	cout<<"以下是节点访问序列"<<endl;
	for(int i = 0; i < order; i++){
		cout<<visitOrder[i]<<" ";
	}
	cout<<endl;
	cout<<"                             ";
	cout<<"以下是生成树的边集"<<endl;
	for(int i = 0; i < edgecount; i++){
		cout<<edgeSet[i][0]<<"->"<<edgeSet[i][1]<<" , ";
	}
	cout<<endl;
	cout<<"                             ";
	cout<<"以下是生成树"<<endl;
	RecursivePrintTree(vertex,0,DFSTree); 
}