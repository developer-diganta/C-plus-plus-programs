#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[1000]={0};
	arr[1]=0;
	arr[2]=1;
	arr[3]=1;
	for(int i=4;i<=n;i++){
		int op1,op2,op3;
		op1=op2=op3=INT_MAX;
		if(i%2==0){
			op1=arr[i/2];
		}
		if(i%3==0){
			op2=arr[i/3];
		}
		op3=arr[i-1];
		int ans=min(min(op1,op2),op3);
		arr[i]=ans+1;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<"->"<<arr[i]<<endl;
	}
	cout<<arr[n];
	return 0;
}