#include<iostream>
#include<vector>
#define Size 1000000
using namespace std;
struct node
{
	int day;
	long long leftSnow;
	node* next;
	node(long long all, int d){
		day = d;
		leftSnow = all;
		next = NULL;
	}
};
int main(){
	int N;
	node* snowHead = NULL;
	long long temperature[Size];
	cin>>N;
	long long melt = 0;//answer
	int first = 1;
	long long sn;
	node* temp;
	for(int i = 0; i < N; i++){
		cin>>sn;
		if(snowHead == NULL){
			snowHead = new node(sn,i);
			temp = snowHead;
		}
		else{
			temp->next = new node(sn,i);
			temp = temp->next;
		}
	}
	/*node* pr = snowHead;
	
	cout<<"left snow:";
	while(pr != NULL){
		cout<<pr->leftSnow<<' ';
		pr = pr->next;
	}
	cout<<endl;
	*/
	temp = snowHead;
	node* tempbefore = NULL;

	for(int i = 0; i < N; i++){
		cin>>temperature[i];
		melt = 0;
		temp = snowHead;
		while(temp != NULL){
			if(temp->day > i)
				break;
			if(temp->leftSnow < temperature[i]){
				melt += temp->leftSnow;
				if(tempbefore == NULL){
					snowHead = temp->next;
					delete temp;
					temp = snowHead;
				}
				else{
					tempbefore->next = temp->next;
					delete temp;
					temp = tempbefore->next;
				}
			}
			else{
				melt += temperature[i];
				temp->leftSnow -= temperature[i];
				temp = temp->next;
			}
		}
		if(first){
			cout<<melt;
			first = 0;
		}
		else{
			cout<<" "<<melt;
		}
	}
	cout<<endl;
}