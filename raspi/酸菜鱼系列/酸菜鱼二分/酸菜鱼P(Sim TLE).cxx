#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
long long arr[200005];
using namespace std;
int main(void){
	memset(arr,0,sizeof(arr));
	int n,t2;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld",&arr[i]);
	}
	scanf("%d",&t2);
	while (t2--)
	{
		int ord;
		scanf("%d",&ord);
		if (ord==1)
		{
			long long i,x;
			scanf("%lld%lld",&i,&x);
			arr[i-1]=x;
		}
		else
		{
			long long x;
			scanf("%lld",&x);
			for (int i = 0; i < n; i++)
			{
				if (arr[i]<x)
				{
					arr[i]=x;
				}
			}
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		printf("%lld ",arr[i]);
	}
	printf("%lld\n",arr[n-1]);
	return 0;
}
 
