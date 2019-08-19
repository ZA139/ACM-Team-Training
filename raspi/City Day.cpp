#include<cstdio>
#include<cstring>
#define INF 99999999999
long long days[10000000];
int main(void){
	memset(days,0,sizeof(days));
	long long n,i;
	int x,y;
	scanf("%lld%d%d",&n,&x,&y);
	for (int i = 0; i < x; i++)
		days[i]=INF;
	for(i=x;i<n+x;i++)
		scanf("%lld",&days[i]);
	for (int i = n+x; i <n+y+x ; i++)
		days[i]=INF;
	for(i=x;i<n+y;i++)
	{
		bool ans=true;
		for(int j=i-x;j<i;j++)
		{
			if(days[j]<days[i]){
				ans=false;
				break;
			}
		}
		if(ans){
		for(int j=i+1;j<=i+y;j++)
			{
				if(days[j]<days[i]){
					ans=false;
					break;
				}
			}
		}
		if(ans)
			break;
	}
	printf("%lld\n",i+1-x);
	return 0;
}
