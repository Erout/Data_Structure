#include<iostream>
#include "huffman.hpp"
int main(){
	huffman obj;
	int act;
	cout<<"**********************************************************************"<<endl;
	cout<<"请输入数字选择获取字母频率的方式："<<endl;
	cout<<"1、读入频率表 \n2、自动统计明文频率"<<endl;
	cout<<"此程序将会对明文文件进行哈夫曼编码，将结果放置到密文文件中（miwen.in)，"<<endl;
	cout<<"随后也会对密文进行解码，结果放置到明文2文件中（mingwen2.in)"<<endl;
	cout<<"输入-1退出本程序"<<endl;
	cout<<"**********************************************************************"<<endl; 
	cin>>act;
 	while(act != -1){
 		if(act == 1){
 			obj.encodeGivenFrequency();
 			obj.decode();
 		}
 		else if(act == 2){
 			obj.encodeFindFrequency();
 			obj.decode();
 		}
 		obj.showCodes();
 		cout<<"*****************************************************"<<endl;
 		cout<<"下面是这棵哈夫曼树的凹入表示法，@代表非叶子节点的其他节点"<<endl;
 		cout<<endl;
 		obj.printTree(obj.getRoot());
 		cout<<"*****************************************************"<<endl;
 		cout<<"**********************************************************************"<<endl;
		cout<<"请输入数字选择获取字母频率的方式："<<endl;
		cout<<"1、读入频率表 \n2、自动统计明文频率"<<endl;
		cout<<"此程序将会对明文文件进行哈夫曼编码，将结果放置到密文文件中（miwen.in)，"<<endl;
		cout<<"随后也会对密文进行解码，结果放置到明文2文件中（mingwen2.in)"<<endl;
		cout<<"输入-1退出本程序"<<endl;
		cout<<"**********************************************************************"<<endl; 
 		cin>>act;
 	}		

	//obj.printTree();
	//system("pause");
}
