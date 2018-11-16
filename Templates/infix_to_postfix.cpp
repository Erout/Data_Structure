/*中缀表达式转后缀表达式*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){

}
string in_to_post(string s){
	string result;
	stack<char> opr;
	string temp;
	opr.push('#');
	for(int i = 0; i < s.size();i++){
		if(isNumber(s[i])){
			temp += s[i];
			continue;
		}
		else{
			result += temp;
			temp = "";
			if(prior())
		}

	}
}