#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool compare(pair<int,int> x,pair<int,int> y){
	int d1=sqrt(x.first*x.first+x.second*x.second);
	int d2=sqrt(y.first*y.first+y.second*y.second);
	return d1<d2;
}

int main(){
	vector<pair<int,int>> cars;
	int n;
	cin>>n;
	// int x,y;
	pair<int,int>x;
	for(int i=0;i<n;i++){
		cin>>x.first>>x.second;
		// cars.push_back(<x,y>)
		cars.push_back(x);
	}

	sort(cars.begin(),cars.end(),compare);
	for(int i=0;i<n;i++){
		// cin>>x>>y;
		// cars.push_back(<x,y>)
		cout<<cars[i].first<<","<<cars[i].second<<"\n";
	
	}




	return 0;
}