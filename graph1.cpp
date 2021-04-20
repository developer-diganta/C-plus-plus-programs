#include<iostream>
#include<list>
using namespace std;

class vertex{
public:
	int V;
	list<int> *l;
	vertex(int V){
		this->V=V;
		l=new list<int>[V];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void print(){
			for(int i=0;i<V;i++){
		cout<<"Vertex : "<<i<<" -> ";
		for(auto j:l[i]){
			cout<<j<<",";
		}
	cout<<endl;
	}
	}
};

int main(){
	int n;
	cin>>n;
	vertex Graph(n);
	Graph.addEdge(0,1);
	Graph.addEdge(1,3);
	Graph.addEdge(2,1);
	Graph.addEdge(0,2);
	Graph.print();
	return 0;
}
