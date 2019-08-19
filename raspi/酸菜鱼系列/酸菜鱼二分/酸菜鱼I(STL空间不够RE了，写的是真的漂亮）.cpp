#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
int gamers[10000000];
long long temp=0;
set<long long>s;
set<long long>::iterator itsetIntTest;
bool check(long long a){
	long long ans=0;
	for (itsetIntTest=s.begin();itsetIntTest!=s.end();itsetIntTest++)
	{
		ans+=gamers[*itsetIntTest]*(a-(*itsetIntTest));
	}
	if(ans>=a)
		return true;
	else
		return false;
}	
int main(void){
	memset(gamers,0,sizeof(gamers));
	ios::sync_with_stdio(false);
	long long a;
	cin>>a;
	for (long long i = 0; i < a; i++)
	{
		long long b;
		cin>>b;
		gamers[b]++;
		s.insert(b);
		temp=max(temp,b);
	}
	long long l=temp,r=1000000000;
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
