#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#define SIZE 100
#define Debug 0
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
class hashTable{
public:
	hashTable();
	~hashTable();
	void constructSequence();
	void setUpTable();
	void printTable();
	int searchTable(string s);
	void printSearchLen();
private:
	string Table[SIZE];
	int searchLen;
	int sequence[SIZE-1];
	long long nameToInt(string name);
	void quickSort(int low, int high, int array[]);
	int partition(int low, int high, int array[]);
};