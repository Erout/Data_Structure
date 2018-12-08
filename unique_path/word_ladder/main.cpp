#include<iostream>
#include<string>
#include<cstring>
#include<vector>;
#define size 50
#define infinite 100000
using namespace std;
struct  word
{
	word* next[size];
	string ele;
	int dis;
	int n;
	word(string s){
		ele = s;
		memset(next,0,sizeof(next));
		n = 0;
		dis = infinite;
	}
};
//判断两个string是否只相差一个字母
bool diffOneChar(string a, string b){
	int diff = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i])
			diff++;
	}
	if(diff == 1)
		return true;
	return false;
}
//使用图，只相差一个字母的单词相互连通
//用dijstra算法求最短路径
int main(){
	string beginWord, endWord;
	cin>>beginWord>>endWord;
	int n;
	cin>>n;
	string temp;
	vector<string> dic;
	word* arr[size];
	int count = 0;
	dic.push_back(beginWord);
	dic.push_back(endWord);
	for(int i = 0; i < n; i++){
		cin>>temp;
		dic.push_back(temp);
	}
	auto it = dic.begin();
	auto iter = it++;
	word* temp1,temp2;
	for(it = dic.begin(); it!= dic.end();it++){
		arr[count] = new word(*it);
		count++;
		temp1 = arr[count];
		for(iter = it; iter != dic.end();iter++){
			if(count < n+2){
				arr[count] = new word(*iter);
				count++;
				temp2 = arr[count];
			}
			if(diffOneChar(*temp1,*temp2)){
				temp1->next[n] = temp2;
				temp1->n++;
				temp2->next[n] = temp1;
				temp2->n++;
			}
		}
	}

}