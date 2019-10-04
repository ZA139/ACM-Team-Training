#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct ass {
	int index;
	int num;
}ss;
int cmp(ss a, ss b) {
	return a.num > b.num;
}
ss tt[1005];
long long cc[1005];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		tt[i].index = i + 1;
		scanf("%d", &tt[i].num);
	}
	long long ans=n;
	sort(tt, tt + n, cmp);
	for (int i = 0; i < n; i++) {
		ans += tt[i].num*i;
		cc[i] = tt[i].index;
	}
	printf("%lld\n", ans);
	for ( int i = 0;i<n-1;i++)
	{
		printf("%lld ", cc[i]);
	}
	printf("%lld\n", cc[n - 1]);
	return 0;
}