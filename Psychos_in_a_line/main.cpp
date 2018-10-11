#include<iostream>
#define Size 10003
#define Debug 0
using namespace std;
struct one{
	one* prev;
	one* next;
	int id_;
	one(int id){
		prev = NULL;
		next = NULL;
		id_ = id;
	}
};
int main(){
	int n;
	one* head = NULL;
	one* tail = NULL;
	cin>>n;
	int tempid;
	for(int i = 0; i < n; i++){
		cin>>tempid;
		if(head == NULL){
			head = new one(tempid);
			tail = head;
		}
		else{
			tail->next = new one(tempid);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}
		if(Debug){
		one* out = head;
		while(out != NULL){
			cout<<out->id_<<" prev:"<<out->prev<<" next:"<<out->next<<endl;
			out = out->next;
		}
	}
	int count = 0;
	int peace = 0;
	one* del;
	while(!peace){
		peace = 1;
		one* temp = tail->prev;
		while(temp != NULL){
			if(Debug)
				cout<<"temp:"<<temp->id_<<" "<<temp<<endl;
			if(temp->id_ > temp->next->id_){
				if(temp->next == tail){
					tail = temp;
				}
				peace = 0;
				del = temp->next;
				temp->next = temp->next->next;
				if(temp->next != NULL){
					temp->next->prev = temp;
				}
			delete del;
			}
		temp = temp->prev;
		}
		if(!peace)
			count++;
		if(Debug){
			one* out = head;
		while(out != NULL){
			cout<<out<<" id:"<<out->id_<<" prev:"<<out->prev<<" next:"<<out->next<<endl;
			out = out->next;
		}
	}
	}
	cout<<count<<endl;
} 