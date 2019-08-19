#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
long long stalls[100010];
long long n, mad;
using namespace std;
bool check(long long a) {
	long long ans = 1;
	long long location = stalls[0];
	for (long long i = 1; i < n; i++)
	{
		if (stalls[i] -location  >= a)
		{
			ans++;
			location = stalls[i];
		}
	}
	return ans >= mad;
}
int main(void) {
	memset(stalls, 0, sizeof(stalls));
	
	scanf("%lld%lld", &n, &mad);
	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &stalls[i]);
	}
	sort(stalls, stalls + n);
	long long l = stalls[0], r = stalls[n - 1];
	while (l<=r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%lld\n", r);
	return 0;
}