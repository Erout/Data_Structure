#include<iostream>
#include<cstring>
#define size 1000
using namespace std;
char graph[size][size];
void DFS(int n, int x ,int y);
int main(){
	int n;
	int first = 1;
	int width = 1;
	memset(graph,' ',sizeof(graph));
	while((cin>>n)&&(n != -1)){
		if(first){
			cout<<"-"<<endl;
			first = 0;
		}
		width = 1;
		memset(graph,' ',sizeof(graph));
		DFS(n,0,0);
		for(int i = 1; i < n; i++)
			width *= 3;
		for(int i = 0; i < width; i++){
			for(int j = 0; j < width; j++){
				cout<<graph[i][j];
			}
			cout<<endl;
		}
		cout<<"-"<<endl;
	}
}
void DFS(int n, int x, int y){
	int wid = 1;
	if(n == 1){
		graph[x][y] = 'X';
	}
	else{
		for(int i = 1; i < n; i++){
			wid *= 3;
		}
		DFS(n-1,x,y);
		DFS(n-1,x+2*wid/3,y);
		DFS(n-1,x+wid/3,y+wid/3);
		DFS(n-1,x,y+2*wid/3);
		DFS(n-1,x+2*wid/3,y+2*wid/3);
	}
} 