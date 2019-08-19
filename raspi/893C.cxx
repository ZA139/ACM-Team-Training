#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
long long num[100005];
vector<int>v[100005];
bool visit[100005];
long long slove(int i){
	long long ans=num[i];
	visit[i]=true;
	for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++)
	{
		if(!visit[*iter])
		ans=min(ans,slove(*iter));
	}
	return ans;
}
int main(int argc, char **argv)
{
	memset(visit,0,sizeof(visit));
	memset(v,0,sizeof(v));
	int m,n;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <=n; i++)
	{
		scanf("%lld",&num[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y<x)
			swap(x,y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	long long ans1=0;
	for (int i = 1; i <=n; i++)
	{
		if(!visit[i])
			{
				ans1+=slove(i);
			}
	}
	printf("%lld\n",ans1);
	return 0;
}
