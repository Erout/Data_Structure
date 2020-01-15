#include "hash.hpp"
using std::cin;
void welcome(){
	cout<<"             ";
	cout<<"-------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                        ";
	cout<<"请输入数字进行相应的操作"<<endl;
	cout<<"                                        ";
	cout<<"1 查看已经建立的哈希表"<<endl;
	cout<<"                                        ";
	cout<<"2 在哈希表中进行搜索"<<endl;
	cout<<"                                        ";
	cout<<"-1 退出程序"<<endl;
}
void function(){
	cout<<"             ";
	cout<<"-------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                        ";
	cout<<"请输入姓名"<<endl;

}
int main(){
	welcome();
	hashTable T;
	T.constructSequence();
	T.setUpTable();
	//T.printTable();
	int act;
	cin>>act;
	string name;
	while(act != -1){
		if(act == 1){
			T.printTable();
		}
		else if(act == 2){
			function();
			cin>>name;
			cout<<"                                        ";
			cout<<"姓名在哈希表中的索引是：";
			cout<<T.searchTable(name)<<endl;
		}
		welcome();
		cin>>act;
	}
}
