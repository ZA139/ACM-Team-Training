#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long prime[10005],b[10005];
inline void isprime() {
	int n = sqrt(10005 + 0.5);
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			for (int j = i * i; j <= 10005; j += i)
				prime[j] = 1;
		}
	}
	return;
}
inline void slove(int a){
	int sum=0,ans=0,cnt=0;
	for(int i=0;i<a;)
	{
		if(sum<a){
			sum+=b[i];
			cnt++;
			i++;
		}
		if(sum==a){
			ans++;
			sum-=b[i-cnt];
			cnt--;
		}
		if(sum>a){	
			sum-=b[i-cnt];
			cnt--;
		}
	}
	printf("%d\n",ans);
	return;
}
int main(void){
	isprime();
	prime[1]=1;
	int cnt=0;
	memset(b,0,sizeof(b));
	for(int i=2;i<10005;i++)
	{
		if(!prime[i])
			b[cnt++]=i;
	}
	int a;
	scanf("%d",&a);
	while(a){
	slove(a);
	scanf("%d",&a);
	}
	return 0;
}
