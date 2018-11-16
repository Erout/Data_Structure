#include<iostream>
using namespace std;
struct node
{
	int val;
	node* left;
	node* right;
	node* parent;
	node(int v){
		val = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
int main(){
	int n;
	cin>>n;
	node* tree[100000];
	node* root;
	int temp;
	node* search;
	int add;
	for(int i = 0; i < n; i++){
		cin>>temp;
		tree[i] = new node(temp);
		if(i == 0){
			root = tree[i];
		}
		else{
			search = root;
			add = 0;
			while(!add){
				if(temp > search->val){
					if(search->right == NULL){
						search->right = tree[i];
						tree[i]->parent = search;
						add = 1;
					}
					else{
						search = search->right;
					}
				}
				else{
					if(search->left == NULL){
						search->left = tree[i];
						tree[i]->parent = search;
						add = 1;
					}
					else{
						search = search->left;
					}
				}
			}
		}
	}
	int first = 1;
	for (int i = 1; i < n; ++i)
	{
		if(first){
			cout<<tree[i]->parent->val;
			first = 0;
		}
		else{
			cout<<" "<<tree[i]->parent->val;
		}

	}
	cout<<endl;
}