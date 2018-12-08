#include "graph.hpp"
#define Debug 1
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
		city[i] = NULL;
		DFSTree[i] = BFSTree[i] = NULL;
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
	if(Debug){
		for(int i = 1; i < 26; i++){
			cout<<i<<" :"<<cityname[i]<<endl;
		}
	}
	ifstream fin("newconnect.in");
	int a,b;
	while(!fin.eof()){
		if(Debug){
			cout<<"多重邻接表的连接情况"<<endl;
			for(int i = 1; i < 26; i++){
				if(city_mul[i] != NULL){
					cout<<i<<cityname[i]<<"->";
					edge* checkedge;
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
					cout<<endl;
				}
			}
		}
		fin>>a;
		fin>>b;
		cout<<a<<" "<<b<<endl;
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
		cout<<"over for link list"<<endl;
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
				cout<<tmp->ivex<<" "<<tmp->ilink<<" "<<tmp->jvex<<" "<<tmp->jlink<<endl;
				if(tmp->ivex == a){
					cout<<"here a"<<endl;
					if(tmp->ilink != NULL){
						cout<<"next"<<endl;
						tmp = tmp->ilink;
					}
					else{
						cout<<"here else,successfully add"<<endl;
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
			cout<<"jump out while"<<endl;
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
			cout<<"jump out while again!!"<<endl;
		}
		cout<<"over for mul link list"<<endl;
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
//邻接多重表广度优先搜索,树也使用邻接多重表存储
void graph::BFS(int vertex){
	queue<headnode*> Q;
	Q.push(city_mul[vertex]);
	headnode* serach;
	edge* tempEdge;
	while(!Q.empty()){
		serach = Q.front();
		Q.pop();
		cout<<serach->id<<" "<<serach->name<<endl;
		serach->mark = 1;
		tempEdge = serach->firstedge;
		while(tempEdge != NULL){
			if(tempEdge->ivex == serach->id){
				//若和正在遍历的点相连的节点未被遍历，那么则将它加到遍历队伍之中
				if(city_mul[tempEdge->jvex]->mark == 0){
					addEdgeToMulLink(tempEdge->ivex,tempEdge->jvex,BFSTree);
					Q.push(city_mul[tempEdge->jvex]);
				}
				tempEdge = tempEdge->ilink;
			}
			else if(tempEdge->jvex == serach->id){
				if(city_mul[tempEdge->ivex]->mark == 0){
					addEdgeToMulLink(tempEdge->ivex,tempEdge->jvex,BFSTree);
					Q.push(city_mul[tempEdge->ivex]);
				}
				tempEdge = tempEdge->jlink;
			}
		}
	}
}
//加边到多重邻接表中
void graph::addEdgeToMulLink(int a, int b, headnode* array[]){
	bool add;
	edge* tmpedg;
	edge* addEdge = new edge(a,b);
	if(array[a] == NULL){
		array[a] = new headnode(a,cityname[a]);
		array[a]->firstedge = addEdge;
	}
	else{
		add = 0;
		tmpedg = array[a]->firstedge;
		while(!add){
			if(tmpedg->ivex == a){
				if(tmpedg->ilink == NULL){
					tmpedg->ilink = addEdge;
					add = 1;
				}
				else{
					tmpedg = tmpedg->ilink;
				}
			}
			else if(tmpedg->jvex == a){
				if(tmpedg->jlink == NULL){
					tmpedg->jlink = addEdge;
					add = 1;
				}
				else{
					tmpedg = tmpedg->jlink;
				}
			}
		}

	}
	if(array[b] == NULL){
		array[b] = new headnode(b,cityname[b]);
		array[b]->firstedge = addEdge;
	}
	else{
		add = 0;
		tmpedg = array[b]->firstedge;
		while(!add){
			if(tmpedg->ivex == b){
				if(tmpedg->ilink == NULL){
					tmpedg->ilink = addEdge;
					add = 1;
				}
				else{
					tmpedg = tmpedg->ilink;
				}
			}
			else if(tmpedg->jvex == b){
				if(tmpedg->jlink == NULL){
					tmpedg->jlink = addEdge;
					add = 1;
				}
				else{
					tmpedg = tmpedg->jlink;
				}
			}
		}
	}
}