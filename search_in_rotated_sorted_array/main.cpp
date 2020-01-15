#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int head, int rear, int target);
int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(9);
	cout<<search(nums,6);
}
int binarySearch(vector<int>& nums, int head, int rear, int target){
	int pivot = (head+rear)/2;
	cout<<"head:"<<head<<" rear:"<<rear<<" pivot:"<<pivot<<endl;
	//ordered part
	int a,b;
	if(nums[pivot] == target)
		return pivot;
	else if(nums[head] == target)
		return head;
	else if(nums[rear] == target)
		return rear;
	if(rear-head <= 2) return -1;
	if(nums[head] <= nums[rear]){
		if(target < nums[pivot]){
			return binarySearch(nums,head,pivot,target);
		}
		else
			return binarySearch(nums,pivot,rear,target);
	}
	else{
		a = binarySearch(nums,head,pivot,target);
		b = binarySearch(nums,pivot,rear,target);
		if(a != -1) return a;
		else if(b != -1) return b;
		else return -1;
	}
}
int search(vector<int>& nums, int target){
	int n = nums.size();
	int pivot = n/2;
	cout<<"pivot" <<pivot<<endl;
	int a,b;
	if(nums[pivot] == target)
		return pivot;
	a = binarySearch(nums,0,pivot,target);
	b = binarySearch(nums,pivot,n-1,target);
	if(a != -1) return a;
	else if(b != -1) return b;
	else return -1;
}
