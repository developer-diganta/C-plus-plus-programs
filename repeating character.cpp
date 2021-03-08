#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue<char> q;
	char freq[27]={0};
	char ch;
	cin>>ch;
	while(ch!='.'){
	q.push(ch);
	int idx=ch-'a';
	freq[idx]++;
	while(!q.empty()){
		int id=q.front()-'a';
		if (freq[id]>1){
			q.pop();
		}
		
		else{
			cout<<q.front()<<endl;
			break;
		}
	}
	if(q.empty()){
		cout<<"-1"<<endl;
	}
		cin>>ch;
	}
	return 0;
}