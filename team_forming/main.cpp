#include<iostream>
#include<algorithm>
#define SIZE 105
using namespace std;
int main(){
	int n;
	cin>>n;
	int skill[SIZE];
	for(int i = 0; i < n; i++)
		cin>>skill[i];
	sort(skill,skill+n);
	int ans = 0;
	for(int j = 0; j < n; j += 2){
		ans += skill[j+1] - skill[j];
	}
	cout<<ans<<endl;
}