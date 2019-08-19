#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
long long stones[1000005];
long long A,B;
long long maxa=0;
using namespace std;
bool check(long long a){
	long long temp=stones[0];
	long long ans=1;
	maxa=0;
	for (int i = 0; i < A; i++)
	{
		if(stones[i]-temp>=a)
			{
				ans++;
				temp=stones[i];
			}
	}
	if(ans>=B)
		return true;
	else
		return false;
}
int main(int argc, char **argv)
{
	memset(stones,0,sizeof(stones));
	scanf("%lld%lld",&A,&B);
	for (int i = 0; i < A; i++)
	{
		scanf("%lld",&stones[i]);
	}
	sort(stones,stones+A);
	long long l=0,r=stones[A-1]-stones[0];
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%lld\n",r);
	return 0;
}

