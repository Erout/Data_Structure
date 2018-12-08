#include<iostream>
#define SIZE 200005
using namespace std;
struct room
{
	int id;
	int cost;
	int mark;
	room* next;
	room(int i,int c){
		id = i;
		cost = c;
		mark = 0;
	}
};
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
		dorm[i]->next = dorm[tmp];
	}
	/*for(int i = 1; i <= n; i++){
		cout<<" cost:"<<dorm[i]->cost<<"dorm"<<i;
		room* next = dorm[i]->next;
		cout<<"->"<<dorm[i]->next->id<<endl;
	}*/
	//for every room, search its minimal costs,and choose the maximal
	int totalcost = 0;
	int minimal = 9999;
	room* reach;
	for(int i = 1; i <= n; i++){
		minimal = 9999;
		reach = dorm[i];
		if(dorm[i]->mark != 0)
			continue;
 		while(reach != NULL && reach->mark != i){
 			reach->mark = i;
 			if(reach->cost < minimal){
 				minimal = reach->cost;
 			}
 			reach = reach->next;
 		}
		totalcost += minimal;
	}
	cout<<totalcost<<endl;
}