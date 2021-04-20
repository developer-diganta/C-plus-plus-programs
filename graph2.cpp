#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;

class Graph{
	unordered_map<string, list<pair<string,int>>> l;
public:
	void addEdge(string x,string y,int dist,bool bidir){
			l[x].push_back(make_pair(y,dist));
			if(bidir){
				l[y].push_back(make_pair(x,dist));
			}
	}

	void print(){
		for(auto i:l){
			cout<<i.first<<" -> ";
			for(auto p:i.second){
				cout<<"("<<p.first<<","<<p.second<<"),";
			}
			cout<<endl;
		}
	}
};

int main(){
	Graph g;
	g.addEdge("A","B",10,true);
	g.addEdge("B","D",20,false);
	g.addEdge("D","A",30,true);
	g.addEdge("B","C",40,false);
	g.print();

	return 0;
}