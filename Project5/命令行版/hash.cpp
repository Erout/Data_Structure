#include "hash.hpp"
#define HkeyMod 77
#define indexMod 100
hashTable::hashTable(){
	for(int i = 0; i < SIZE-1; i++)
		sequence[i] = 0;
	searchLen = 0;
}
hashTable::~hashTable(){};
void hashTable::constructSequence(){
	if(Debug) cout<<"here"<<endl;
	int order = 0;
	int temp = 0;
	while(order != SIZE-1){
		sequence[order++] = rand()%50;
	}
	quickSort(0,SIZE-2,sequence);
}
void hashTable::setUpTable(){
	if(Debug) cout<<"setUpTable"<<endl;
	ifstream fin("name2.in");
	string s;
	int Hkey,index,order;
	while(!fin.eof()){
		fin>>s;
		Hkey = nameToInt(s) % HkeyMod;
		if(Debug) cout<<s<<" Hkey"<<Hkey<<endl;
		if(Table[Hkey].size() == 0){
			Table[Hkey] = s;
			searchLen++;
		}
		else{
			order = 0;
			index = (sequence[order++]+Hkey) % indexMod;
			searchLen++;
			while(Table[index].size() != 0){
				index = (sequence[order++]+Hkey) % indexMod;
				searchLen++;
			}
			Table[index] = s;
		}
	}
}
void hashTable::printTable(){
	if(Debug) cout<<"printTable"<<endl;
	for(int i = 0; i < SIZE; i++)
		if(Table[i].size()){
			cout<<"                                           ";
			cout<<i<<"    "<<Table[i]<<endl;
		}
	cout<<"                                           ";
	cout<<"平均搜索长度为"<<(double)searchLen/30<<endl;
}
int hashTable::searchTable(string s){
	int Hkey,index,order;
	Hkey = nameToInt(s) % HkeyMod;
	if(Table[Hkey] == s){
		return Hkey;
	}
	else{
		order = 0;
		index = (sequence[order++]+Hkey) % indexMod;
		searchLen++;
		while(Table[index] != s && order < SIZE-1){
			index = (sequence[order++]+Hkey) % indexMod;
		}
		if(order == SIZE-1) return -1;
		else return index;
	}
}
void hashTable::printSearchLen(){
	cout<<searchLen<<endl;
}
long long hashTable::nameToInt(string name){
	int len = name.size();
	int end;
	if(len < 4) 
		end = 0;
	else 
		end = len-4;
	int exp = 1;
	int ans = 0;
	for(int i = len-1; i >= 0; i--){
		ans += name[i]*exp;
		exp *= 2;
	}
	return ans;
}
void hashTable::quickSort(int low, int high, int array[]){
	int pivot;
	if(low < high){
		pivot = partition(low,high,array);
		quickSort(low,pivot-1,array);
		quickSort(pivot+1,high,array);
	}
}
int hashTable::partition(int low, int high, int array[]){
	int key = array[low];
	while(low < high && array[high] >= array[low])
		high--;
	array[low] = array[high];
	while(low < high && array[low] <= array[high])
		low++;
	array[high] = array[low];
	array[low] = key;
	return low;
}