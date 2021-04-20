/*In this program, say there is a queue of N people and priority
simply is not about greater int...Here say people with certain criteria 
are given priority...In such a case a functor will be passed to priority queue
since it does not simply take a function but accepts a class*/
#include<iostream>
#include<queue>
using namespace std;

class Person{
	public:
		string name;
		int age;

		Person(string n,int a){
			name=n;
			age=a;
		}
};

class PersonCompare{
public:
	bool operator()(Person A,Person B){
		return A.age<B.age;
	}
};

int main(){
	int n;
	cin>>n;
	priority_queue<Person,vector<Person>,PersonCompare>pq;//passing a FUNCTOR
	for(int i=0;i<n;i++){
		string name;
		int age;
		cin>>name>>age;
		Person p(name,age);
		pq.push(p);
	}
	int k=3;//check notes 
	for(int i=0;i<k;i++){
		Person p=pq.top();
		cout<<p.name<<" "<<p.age<<endl;
		pq.pop();
	}

	return 0;
}