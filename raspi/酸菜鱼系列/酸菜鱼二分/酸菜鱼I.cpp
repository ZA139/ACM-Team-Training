#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
long long gamers[100005];
long long temp=0,n;
bool check(long long a){
	long long ans=0;
	for(long long i=0;i<n;i++){
	ans+=a-gamers[i];
	}
	if(ans>=a)
		return true;
	else
		return false;
}	
int main(void){
	memset(gamers,0,sizeof(gamers));
	ios::sync_with_stdio(false);
	cin>>n;
	for (long long i = 0; i < n; i++)
	{
		cin>>gamers[i];
		temp=max(temp,gamers[i]);
	}
	long long l=temp,r=1000000000*2;
	while(l<= r){
		long long mid=(l+r)>>1;
	if(check(mid))
		r=mid-1;
	else
		l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
