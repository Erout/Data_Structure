#include<iostream>
#include<set>
#include<queue>
using namespace std;
struct node
{
	node* father;
	int val;
	int floor;
	node(int v){
		val = v;
		floor = 0;
		father = NULL;
	}
};
long long pow(long long coe,long long exp,long long p);
int main(){
	long long u,v,p;
	cin>>u>>v>>p;
	//pow(244,989);
	set<long long> uBFS;
	set<long long> vBFS;
	uBFS.insert(u);
	vBFS.insert(v);
	queue<node*> uExt;
	queue<node*> vExt;
	node* Uroot = new node(u);
	node* Vroot = new node(v);
	uExt.push(Uroot);
	vExt.push(Vroot);
	bool getResult = 0;
	if(u == v){
		cout<<0<<endl;
		getResult = 1;
	}
	node* Utemp,*Vtemp;
	int Ufloor = 0,Vfloor = 0;
	node* result;
	long long r;
	while(!getResult){
		//u进行一层扩展
		while(!getResult && uExt.front()->floor == Ufloor){
			Utemp = uExt.front();
			uExt.pop();
			u = Utemp->val;
			for(int i = 0; i < 3; i++){
				switch(i){
					case 0:
					r = (u+1)%p;
					break;
					case 1:
					r = (u+p-1)%p;
					break;
					case 2:
					r = pow(u,p-2,p)%p;
					//cout<<"pow:"<<pow(u,p-2)<<endl;
					break;
				}
				//cout<<"ur:"<<r<<" ";
				result = new node(r);
				result->floor = Utemp->floor+1;
				result->father = Utemp;
				uBFS.insert(r);
				uExt.push(result);
				if(vBFS.find(r) != vBFS.end()){
					cout<<Ufloor+Vfloor+1<<endl;
					getResult = 1;
					return 0;
				}
			}
			//cout<<"floor"<<Ufloor<<endl;
		}
		Ufloor++;
		//v进行一层扩展
		while(!getResult && vExt.front()->floor == Vfloor){
			Vtemp = vExt.front();
			vExt.pop();
			v = Vtemp->val;
			for(int i = 0; i < 3; i++){
				switch(i){
					case 0:
					r = (v+1)%p;
					break;
					case 1:
					r = (v+p-1)%p;
					break;
					case 2:
					r = pow(v,p-2,p)%p;
					//cout<<"pow"<<pow(v,p-2)<<endl;
					break;
				}
			//	cout<<"vr:"<<r<<" ";
				result = new node(r);
				result->floor = Vtemp->floor+1;
				result->father = Vtemp;
				vBFS.insert(r);
				vExt.push(result);
				if(uBFS.find(r) != uBFS.end()){
					getResult = 1;
					cout<<Vfloor+Ufloor+1<<endl;
					return 0;
				}
			}
			//cout<<"floor"<<Vfloor<<endl;
		}
		Vfloor++;
	}
}
long long pow(long long coe,long long exp,long long p){
	//cout<<endl;
	//cout<<"coe"<<coe<<" exp"<<exp;
	long long result = 1;
	while(exp){
		if(exp&1)
			result = result*coe%p;
		coe = coe*coe%p;
		exp>>=1;
	}
	//cout<<" result"<<result<<endl;
	return result;
}