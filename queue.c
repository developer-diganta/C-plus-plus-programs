#include<iostream>
#include<queue>

using namespace std;

int main(){
	queue<int> q;
	for(int i=1;i<=10;i++)
		q.push(i);
	while(!q.isEmpty()){
		cout<<q.front(i)<<" <- ";
		q.pop();
	}
	cout<<endl;
	return 0;
}