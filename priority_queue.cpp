#include<iostream>
#include<queue>

using namespace std;

int main(){
	priority_queue<int> pq;//based by default on a max heap
	/*to make it min heap
	priority_queue<int,vector<int>,greater<int>> pq;
	only this statement is required!*/
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		pq.push(no);//O(logN)
	}

	//remove
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}