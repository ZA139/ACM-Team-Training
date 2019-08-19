#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
long long boxer[1500005],tmp[1500005];
void slove(int a){
	if(!boxer[a-1]&&a-1>0)
		boxer[a-1]=1;
	else if(!boxer[a])
		boxer[a]=1;
	else if(!boxer[a+1])
		boxer[a+1]=1;
	return;
}
int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	memset(boxer,0,sizeof(boxer));
	memset(tmp,0,sizeof(tmp));
	for (int i = 0; i < t; i++)
	{
		scanf("%lld",&tmp[i]);
	}
	std::sort(tmp,tmp+t);
	for (int i = 0; i < t; i++)
	{
		slove(tmp[i]);
	}
	
	//boxer[1500000]=0
	long long cnt=0;
	for (int i = 1; i < 1500000; i++)
	{
		if(boxer[i])
			cnt++;
	}
	if(cnt<t)
	printf("%lld\n",cnt);
	else
	printf("%d\n",t);
	return 0;
}
