#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack <int> &s,int x){

	if(s.empty()){
		s.push(x);
		return;
	}

	int data=s.top();
	insertatbottom(s,data);
	s.push(data);
	return;
}


void reverse(stack <int> &s){

	if(s.empty()){
		return;
	}

	int x=s.top();
	s.pop();
	reverse(s);
	insertatbottom(s,x);
}


int main(){
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	   while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

	return 0;


}