#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,t,ans=0;
double stick[1000000];
int visit[1000000];
bool dfs(int num,int len,int root)
{
	if(num==n)
		return 1;
	for(int i=root;i<n;i++)
	{
		if(stick[i]>=len&&visit[i])
		{
			visit[i]=1;
			dfs(num+1,len,i);
			visit[i]=0;
		}
	}
	return dfs(0,len+1,0);	
}
int main(void)
{
	int minx=9999;
	scanf("%lld",&t);
	while(t--)
	{
		memset(visit,0,sizeof(visit));
		memset(stick,0,sizeof(stick));
		scanf("%lld",&n);
		for(long long i=0;i<n;i++)
		{
			scanf("%lf",&stick[i]);
			minx=minx>stick[i]?stick[i]:minx;
			ans+=stick[i];
		}
		if(ans%4)
			cout<<"no\n";
		else{
		if(dfs(0,minx,0))
			cout<<"yes\n";
		else
			cout<<"no\n";
		}
	}
	return 0;
}z
	
