#include<cstdio>
#include<algorithm>
using namespace std;
long long a[4005], b[4005], c[4005], d[4005];
long long ab[16000005];
long long cd[16000005];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
	{
		scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
	}
	int cnt = 0;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab[cnt++] = a[i] + b[j];
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++)	
	{
		for (int j = 0; j < n; j++)
		{
			cd[cnt++] = c[i] + d[j];
		}
	}
	sort(cd, cd + cnt );
	long long ans = 0;
	for (int i = 0; i <cnt; i++)
	{
		long long a = -ab[i];
		ans += upper_bound(cd, cd + cnt , a) - lower_bound(cd, cd + cnt , a);
	}
	printf("%lld\n", ans);
	return 0;
}