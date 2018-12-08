#include<iostream>
#include<vector>
#define Size 1000
using namespace std;
struct node
{
	int weight;
	int num;
	int color;
	vector<node*> connect;
	node(int w,int n){
		weight = w;
		num = n;
		color = 0;
	}
};
int max(node* part[],int n);
int main(){
	int n,m;
	cin>>n>>m;
	int v;
	node* part[Size];
	for(int i = 1; i <= n; i++){
		cin>>v;
		part[i] = new node(v,i);
	}
	int a,b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		part[a]->connect.push_back(part[b]);
		part[b]->connect.push_back(part[a]);
	}
	/*for(int i = 1; i <= n; i++){
		cout<<part[i]<<" "<<part[i]->weight<<" "<<part[i]->num<<endl;
	}*/
	int total = 0;
	int rm;
	while(m){
		rm = max(part,n);
		//cout<<"rm"<<rm<<endl;
		auto it = part[rm]->connect.begin();
		for(it; it != part[rm]->connect.end();it++){
			//cout<<" "<<*it<<" "<<(*it)->num<<endl;
			if((*it) != NULL && (*it)->color == 0){
				total += (*it)->weight;
				m--;
			}
		}
		part[rm]->color = 1;
		part[rm] = NULL;
	}
	cout<<total<<endl;
}
int max(node* part[],int n){
	int max = 0;
	int maxvalue = 0;
	for(int i = 1; i <= n; i++){
		if(part[i] != NULL){
			if(part[i]->weight > maxvalue){
				maxvalue = part[i]->weight;
				max = i;
			}
		}
	}
	return max;
}
