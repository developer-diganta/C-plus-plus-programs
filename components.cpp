#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

template <typename T>
class Graph{
	map<T,list<T>> l;
public:
	void addEdge(T x,T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfsHelper(T src,map<T,bool> &visited){
		cout<<src<<" ";
		visited[src]=true;
		for(auto it:l[src]){
			if(!visited[it]){
				dfsHelper(it,visited);
			}
		}
	}

	void dfs(){
		map<T,bool> visited;
		for(auto it:l){
			T node=it.first;
			visited[node]=false;
		}
		int cnt=0;
		for(auto p:l){//keeping count of components
			
			if(!visited[p.first]){
				cout<<"Component "<<cnt<<" -> ";
				dfsHelper(p.first,visited);
				cnt++;
				cout<<endl;
			}
			
			
		}
	}

};

int main(){
	Graph<int>g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(5,6);
	g.addEdge(5,6);
	g.addEdge(5,7);
	g.addEdge(8,8);
	g.dfs();
	return 0;
}
