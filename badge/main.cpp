#include<iostream>
#include<cstring>
using namespace std;
struct node
{
	node* next;
	int num;
	node(int n){
		num = n;
	}
};
int main(){
	int n;
	cin>>n;
	//int pi[1000];
	int p;
	node* stu[1001];
	memset(stu,0,sizeof(stu));
	for(int i = 1; i <= n; i++){
		cin>>p;
		if(stu[p] == NULL){
			stu[p] = new node(p);
		}
		if(stu[i] == NULL){
			stu[i] = new node(i);
		}
		stu[i]->next = stu[p];
	}

	int tag[1001];
	int seccesor;
	for(int i = 1; i <= n; i++){
		memset(tag,0,sizeof(tag));
		tag[i] = 1;
		seccesor = stu[i]->next->num;
		while(tag[seccesor] == 0){
			tag[seccesor]++;
			seccesor = stu[seccesor]->next->num;
		}
		if(i != 1)
			cout<<" "<<seccesor;
		else
			cout<<seccesor;
	}
	cout<<endl;
}