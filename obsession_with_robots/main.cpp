#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
int main(){
	string s;
	cin>>s;
	int map[SIZE][SIZE];
	int x = 50, y = 50;
	int sucx = -1, sucy = -1;
	map[x][y] = 1;
	for(int i = 0; i < s.size(); i++){
		sucx = x;
		sucy = y;	
		switch(s[i]){
			case 'U':
			x -= 1;
			break;
			case 'D':
			x += 1;
			break;
			case 'L':
			y -= 1;
			break;
			case 'R':
			y += 1;
			break;
		}
		if(map[x][y] == 1){
			cout<<"BUG"<<endl;
			return 0;
		}
		map[sucx][sucy] = 0;
		if(map[x-1][y] == 1 || map[x+1][y] == 1 || map[x][y-1] == 1 || map[x][y+1] == 1){
			cout<<"BUG"<<endl;
			return 0;
		}
		map[sucx][sucy] = 1;
		map[x][y] = 1;
	}
	cout<<"OK"<<endl;
}