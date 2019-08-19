#include<iostream>
#include<cstring>
using namespace std;
long long dp[1000];
int main(void){
	ios::sync_with_stdio(false);
	memset(dp,0,sizeof(dp));
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	for(int i=4;i<50;i++){
	dp[i]=dp[i-1]+dp[i-2];
	}
	int t;
	cin>>t;
	while(t--){
	int a;
	cin>>a;
	cout<<dp[a]<<endl;
	}
	return 0;
}
