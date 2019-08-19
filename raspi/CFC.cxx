#include <cstdio>
long ans=0,d;
int t,i;
long gcd(long a,long b){
	return b==0?a:gcd(b,a%b);
}	
int main(int argc, char **argv)
{
	long gong=0;
	scanf("%d",&t);
	scanf("%ld",&d);
	gong=d;
	for (i = 1; i < t&&gong!=1; i++)
	{
		scanf("%ld",&d);
		gong=gcd(d,gong);
	}
	for (i = 1; i*i <=gong ; i++)
	{
		if(gong%i==0)
		{
			ans++;
			if(i*i!=gong)
				ans++;
		}
	}
	printf("%ld\n",ans);
	return 0;
}

