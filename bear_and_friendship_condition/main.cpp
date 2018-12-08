#include<iostream>
#include<cstring>
#include<vector>
#define Size 150003
using namespace std;
struct node
{
	node* next;
	int n;
	node(int n_){
		n = n_;
		next = NULL;
	}	
};
struct Headnode
{
	int num;
	node* n;
	Headnode(int num_){
		num = num_;
		n = NULL;
	}
};

int main(){
	int n,m;
	cin>>n>>m;
	int a,b;
	Headnode* head[Size];
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		if(head[a] == NULL){
			head[a] = new Headnode(a);
		}
		if(head[b] == NULL){
			head[b] = new Headnode(b);
		}
		node* tmp = head[a]->n;
		if(tmp == NULL){
			head[a]->n = new node(b);
		}
		else{
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next = new node(b);
		}
		tmp = head[b]->n;
		if(tmp == NULL){
			head[b]->n = new node(a);
		}
		else{
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next = new node(a);
		}
	}
	/*for(int i = 1; i <= n; i++){
		if(head[i] != NULL){
			cout<<"head:"<<head[i]<<" "<<head[i]->num<<" ";
			node* link = head[i]->n;
			while(link != NULL){
				cout<<"link:"<<link<<" "<<link->n<<" ";
				link = link->next;
			}
			cout<<endl;
		}
	}*/
	int src,mid,dst;
	int find = 0;
	node* search, *searchmid,*searchdst,*searchsrc;
	for(int i = 1; i <= n;i++){
		if(head[i] != NULL){
			src = head[i]->num;
			search = head[i]->n;
			while(search != NULL){
				mid = search->n;
				searchdst = head[mid]->n;
				while(searchdst != NULL){
					dst = searchdst->n;
					if(src != dst){
						searchsrc = head[i]->n;
						find = 0;
						while(searchsrc != NULL){
							if(searchsrc->n == dst){
								find = 1;
								break;
							}
							searchsrc = searchsrc->next;
						}
						if(find == 0){
							cout<<"NO"<<endl;
							return 0;
						}
					}
					searchdst = searchdst->next;
				}
				search = search->next;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
	
}
//to decide whether a graph is transitive