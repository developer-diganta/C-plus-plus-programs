#include<iostream>
#include<set>
using namespace std;

int main(){

	int arr[]={10,21,13,9,10,56,23,10,1,233,12,23};
	int n=sizeof(arr)/sizeof(int);

	set<int> s;
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}
		auto it=s.find(11);
	s.erase(it);
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<*(it)<<",";
	}



	return 0;
}

