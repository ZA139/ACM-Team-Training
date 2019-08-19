#include<cstring>
#include<cstdio>
#include<algorithm>
int a[1005][5];
long long score[1005];
char ch;
long long findmax(int b){
	long long ans=0;
	for (int i = 0; i <5; i++)
	{
		ans=a[b][i]>ans?a[b][i]:ans;
	}
	return ans;
}	
int main(void){
	memset(a,0,sizeof(a));
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ch=getchar();
			while(ch=='\n'||ch=='\r')
				ch=getchar();
			if(ch=='A')
				a[j][0]++;
			if(ch=='B')
				a[j][1]++;
			if(ch=='C')
				a[j][2]++;
			if(ch=='D')
				a[j][3]++;
			if(ch=='E')
				a[j][4]++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%lld",&score[i]);
	}
	long long ans=0;
	for (int i = 0; i < m; i++)
	{
		ans+=findmax(i)*score[i];
	}
	printf("%lld\n",ans);
	return 0;
}
