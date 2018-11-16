#include<iostream>
using namespace std;
struct node
{
	int weight;
	int dis;
	node* parent;
	node* left;
	node* right;
	node(int w){
		weight = w;
		dis = 0;
		left = NULL;
		right = NULL;
	}
};
void countDis(node* n);
void print(node* n){
	if(n == NULL)
		return;
	for(int i = 0; i < n->dis;i++)
		cout<<n->weight;
	cout<<endl;
	print(n->left);
	print(n->right);
}
int main(){
	int n;
	cin>>n;
	int weight[100];
	node* leaf[100];
	node* queue[100];
	for(int i = 0; i < n; i++){
		cin>>weight[i];
		queue[i] = new node(weight[i]);
		leaf[i] = queue[i];
	}
	int count = n;

	while(count != 1){
		int min1 = 0;
		int min2 = -1;
		for(int i = 1; i < count; i++){
			if(queue[i]->weight < queue[min1]->weight){
				if(min2 == -1){
					min2 = min1;
					min1 = i;
				}
				else if(queue[min1]->weight < queue[min2]->weight){
					min2 = min1;
					min1 = i;
				}
				else{
					min1 = i;
				}
			}
			else if(min2 == -1){
				min2 = i;
			}
			else if(queue[i]->weight <queue[min2]->weight){
				min2 = i;
			}
		}
		node* build = new node(queue[min1]->weight + queue[min2]->weight);
		queue[min1]->parent = build;
		queue[min2]->parent = build;
		build->left = queue[min1];
		build->right = queue[min2];
		queue[min1] = build;
		queue[min2] = queue[--count];
	}
	countDis(queue[0]);
	//print(queue[0]);
	int total = 0;
	for(int i = 0; i < n; i++){
		total += leaf[i]->weight * leaf[i]->dis;
	}
	cout<<total<<endl;

}
void countDis(node* n){
	if(n == NULL)
		return;
	if(n->parent != NULL)
		n->dis = n->parent->dis+1;
	cout<<"n"<<n<<" weight:"<<n->weight<<" left:"<<n->left<<" right"<<n->right<<endl;
	countDis(n->left);
	countDis(n->right);
}