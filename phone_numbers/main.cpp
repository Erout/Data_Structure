#include<iostream>
#include<algorithm>
#include<set>
#define SIZE 50000
using namespace std;
string wordToPhone(string word);
int main(){
	string s;
	string dic[SIZE];
	cin>>s;
	int wordNum;
	//map<string,int> M;
	set<string> S;
	int times;
	string correspnd[SIZE];
	while(s != "-1"){
		cin>>wordNum;
		for(int i = 0; i < wordNum; i++){
			cin>>dic[i];
			correspnd[i] = wordToPhone(dic[i]);
		}
	}
}
string wordToPhone(string word){
	string s;
	for(int i = 0; i < word.size();i++){
		switch(word[i]){
			case 'i': case 'j': s += '1'; break;
			case 'a': case 'b': case 'c': s += '2'; break;
			case 'd': case 'e': case 'f': s += '3'; break;
			case 'g': case 'h': s += '4'; break;
			case 'k': case 'l': s += '5'; break;
			case 'm': case 'n': s += '6'; break;
			case 'p': case 'r': case 's': s += '7'; break;
			case 't': case 'u': case 'v': s += '8'; break;
			case 'w': case 'x': case 'y': s += '9'; break;
			case 'o': case 'q': case 'z': s += '0'; break;

		}
	}
	return s;
}