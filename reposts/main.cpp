#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	vector<node*> next;
	node* parent;
	int dis;
	string person;
	string father;
	node(string s){
		person = s;
		parent = NULL;
		dis = 0;
	}
};
string formatName(string name);
int main(){
	int n;
	cin>>n;
	string name1;
	string repo;
	string name2;
	int max = 0;
	node* root = new node("POLYCARP");
	vector<node*> TreeNode;//nodes already added to the tree
	TreeNode.push_back(root);
	queue<node*> waitToAdd;//nodes that have met but still can't added to the tree
	for(int i = 0; i < n; i++){
		cin>>name1>>repo>>name2;
		name1 = formatName(name1);
		name2 = formatName(name2);
		bool addsuccess = 0;
		for(auto it = TreeNode.begin();it != TreeNode.end();it++){
			if((*it)->person == name2){
				node* add = new node(name1);
				add->parent = (*it);
				add->dis = (*it)->dis+1;
				if(add->dis > max)
					max = add->dis;
				(*it)->next.push_back(add);
				TreeNode.push_back(add);
				addsuccess = 1;
				break;
			}
		}
		if(!addsuccess){
			node* notadd = new node(name1);
			notadd->father = name2;
			waitToAdd.push(notadd);
		}
	}
	while(!waitToAdd.empty()){
		node* temp = waitToAdd.front();
		waitToAdd.pop();
		bool addsuccess = 0;
		for(auto it = TreeNode.begin();it != TreeNode.end();it++){
			if((*it)->person == temp->father){
				temp->parent = (*it);
				temp->dis = (*it)->dis + 1;
				if(temp->dis > max)
					max = temp->dis;
				(*it)->next.push_back(temp);
				TreeNode.push_back(temp);
				addsuccess = 1;
				break;
			}
		}
		if(addsuccess == 0)
			waitToAdd.push(temp);
	}
	cout<<max+1<<endl;
}
string formatName(string name){
	for(int i = 0; i < name.size();i++){
		if(name[i] >= 'a' && name[i] <='z')
			name[i] = name[i]-' ';
	}
	return name;
}