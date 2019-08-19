/*#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
long long m[100005],a[100005];
void print(long long a[],int t){
	for (int i = 0; i < t; i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<endl;
	return;
}
int main(void){
	memset(m,0,sizeof(m));
	memset(a,0,sizeof(a));
	int t;
	scanf("%d",&t);
	long long temp;
	for (int i = 0; i < t; i++)
	{
		scanf("%lld",&temp);
		a[i]=labs(1-temp);
		m[i]=labs(-1-temp);
	}
	sort(a,a+t);
	sort(m,m+t);
	long long ans=0;
	for (int i = 0; i < t; i++)
	{
		ans+=a[i];
	}
	print(a,t);
	print(m,t);
	long long temp1=ans;
	for (int i = 0; i < t-1; i+=2)
	{
		ans-=(a[t-i-1]+a[t-i-2]);
		ans+=(m[i]+m[i+1]);
		temp1=min(ans,temp1);
	}
	printf("%lld\n",temp1);
	return 0;
}
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
long long m[100005],a[100005];
void print(long long a[],int t){
	for (int i = 0; i < t; i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<endl;
	return;
}
int main(void){
	long long mi=9999999;
	int n;
	scanf("%d",&n);
	long long temp;
	int cnt1=0,cnt2=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld",&temp);
		if(temp<0)
			m[cnt1++]=labs(-1-temp);
		else{
			a[cnt2++]=labs(1-temp);
			mi=min(mi,temp);
		}
	}
	long long ans=0;
	for (int i = 0; i < cnt1; i++)
	{
		ans+=m[i];
	}
	for (int i = 0; i < cnt2; i++)
	{
		ans+=a[i];
	}
	//print(a,cnt2-1);
	//print(m,cnt1-1);
	if(cnt1&1){
		ans-=labs(1-mi);
		ans+=labs(-1-mi);
	}
	printf("%lld\n",ans);
	return 0;
}
	
