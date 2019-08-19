#include<cstdio>
#include<cstring>
long long s[1005],cnt=1;
int main(void){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long ans=0;
		memset(s,0,sizeof(s));
		int n;
		scanf("%d",&n);
		for (int i = 0; i <n ; i++)
		{
			scanf("%lld",&s[i]);
		}
		for (int i = 0; i <n ; i++)
		{
			for (int j = i+1; j <n ; j++)
			{
				if(s[i]>s[j])
					ans++;
			}
		}
		printf("Scenario #%lld:\n%lld\n",cnt++,ans);
		
	}
	return 0;
}
