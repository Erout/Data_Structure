#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct vol
{
	string text;
	int index;
	vol* next;
	vol(string s,int i){
		text = s;
		index = i;
		next = NULL;
	}
};
struct word
{
	string text;
	vol* first;
	int dis;
	int color;
	word(string s){
		text = s;
		first = NULL;
		dis = -1;
		color = 0;
	}
};
bool chageable(string a, string b);
void addpath(word* a, word* b,int indexa, int indexb);
//BFS
int main(){
	string beginword,endword;
	int n;
	cin>>beginword>>endword;
	cin>>n;
	word* dic[55];
	dic[50] = new word(beginword);
	dic[51] = new word(endword);
	string temp;
	for(int i = 0; i < n; i++){
		cin>>temp;
		dic[i] = new word(temp);
		for(int j = 0; j < i; j++){
			if(chageable(dic[i]->text,dic[j]->text)){
 				addpath(dic[i],dic[j],i,j);
			}
		}
		if(chageable(dic[i]->text,dic[50]->text))
			addpath(dic[i],dic[50],i,50);
		if(chageable(dic[i]->text,dic[51]->text))
			addpath(dic[i],dic[51],i,51);
	}
	//BFS Search
	queue<word*> Q;
	dic[50]->color = 1;
	dic[50]->dis = 0;
	Q.push(dic[50]);
	word* search;
	vol* temp1;
	while(!Q.empty()){
		search = Q.front();
		Q.pop();
		temp1 = search->first;
		while(temp1 != NULL){
			if(dic[temp1->index]->color == 0){
				dic[temp1->index]->color = 1;
				dic[temp1->index]->dis = search->dis+1;
				Q.push(dic[temp1->index]);
			}
			temp1 = temp1->next;
		}
	}
	cout<<dic[51]->dis+1<<endl;
} 
bool chageable(string a, string b){
	if(a.size() != b.size())
		return false;
	int diff = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i])
			diff++;
	}
	if(diff == 1)
		return true;
	else 
		return false;
}
void addpath(word* a, word* b,int indexa, int indexb){
	vol* add;
	add = a->first;
	if(add == NULL)
		a->first = new vol(b->text,indexb);
	else{
		while(add->next != NULL)
			add = add->next;
		add->next = new vol(b->text,indexb);
	}
	add =b->first;
	if(add == NULL)
		b->first = new vol(a->text,indexa);
	else{
		while(add->next != NULL){
			add = add->next;
		}
		add->next = new vol(a->text,indexa);
	}
}