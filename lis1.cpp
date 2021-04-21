#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int dp[1000]={0};
	for(int i=0;i<n;i++){
		int ans=0;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				ans=max(ans,dp[j]);
			}
		}
		dp[i]=ans+1;
	}


	int ans=0;
	// for(int i=0;i<n;i++)
	// 	cout<<i<<"->"<<dp[i]<<endl;

	for(int i=0;i<n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}