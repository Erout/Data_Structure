#include<iostream>
#define SIZE 200005
using namespace std;
struct room
{
	int id;
	int cost;
	int mark;
	bool getAns;
	room* next;
	room(int i,int c){
		id = i;
		cost = c;
		mark = 0;
		getAns = 0;
		next = NULL;
	}
};
int searchRoom(room* dorm[],int v);
int main(){
	int n;
	cin>>n;
	int cost[SIZE];
	room* dorm[SIZE];
	for(int i = 1; i <= n; i++){
		cin>>cost[i];
		dorm[i] = new room(i,cost[i]);
	}
	int tmp;
	int suc = -1;
	for(int i = 1; i <= n; i++){
		cin>>tmp;
		if(tmp != i)
			dorm[i]->next = dorm[tmp];
		else
			dorm[i]->next = NULL;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(dorm[i]->mark == 0){
			ans += searchRoom(dorm,i);
		}
	}
	cout<<ans<<endl;
}
int searchRoom(room* dorm[],int v){
	room* temp = dorm[v];
	if(temp->getAns) return 0;
	int circle = 0;
	room* renew;
	while(temp != NULL){
		//have got answer
		if(temp->getAns){
			renew = dorm[v];
			while(renew->getAns == 0){
				renew->getAns = 1;
				renew = renew->next;
			}
			return 0;	
		} 
		if(temp->mark == 1){
			//exist circle
			renew = dorm[v];
			while(renew != temp){
				renew->getAns = 1;
				renew = renew->next;
			}
			circle = 99999;
			while(renew->getAns == 0){
				renew->getAns = 1;
				if(renew->cost < circle)
					circle = renew->cost;
				renew = renew->next;
			}
			return circle;
		}
		else{
			temp->mark = 1;
			temp = temp->next;
		}
	}
	//it is a list nerver has been searched
	if(temp == NULL){
		renew = dorm[v];
		while(renew != NULL){
			renew->getAns = 1;
			if(renew->next == NULL){
				return renew->cost;
			}
			renew = renew->next;
		}
	}
}