#include<iostream>
#include<set>	
#include"linkNode.h"
using namespace std;
linkNode* getIntersectionNode(linkNode* headA,linkNode* headB){
	linkNode* p = headA;
	linkNode* q = headB;
	set<linkNode*> S;
	while(p != NULL){
		S.insert(p);
		 p = p->next;
	}
	while(q != NULL){
		if(S.find(q) != S.end())
			return q;
		q = q->next;
	}
	return NULL;
}
int main(){
	linkNode* a = new linkNode(2);
	linkNode* temp = a;
	for(int i = 3; i < 6; i++){
		temp->next = new linkNode(i);
		temp = temp->next;
	}
	linkNode* b = new linkNode(-3);
	temp = b;
	for(int i = -2; i < 5; i++){
		temp->next = new linkNode(i);
		temp = temp->next;
	}
	cout<<getIntersectionNode(a,b);
}