#include<iostream>
#include<cstring>
#include<algorithm>
long long contests[1000000];
using namespace std;
int main(void){
	memset(contests,0,sizeof(contests));
	long long a;
	ios::sync_with_stdio(false);
	cin>>a;
	for(long long i=0;i<a;i++)
	{
		cin>>contests[i];
	}
	sort(contests,contests+a);
	long long ans=0,day=1;
	for (long long i = 0; i <10000000; i++)
	{
		if(day<=contests[i])
		{
			ans++;
			day++;
		}
		if(!contests[i])
			break;
	}
	
	printf("%lld\n",ans);
	return	0;
}
