#include<cstdio>
#include<cstring>
typedef long long ll;
int main(void) {
	ll m, n, k, ans;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%lld%lld%lld", &n, &m, &k);
		ans = m + 1;
		ll temp = (m / (n - k + 1))*(k - 1);
		ans += temp;
		ans += k;
		ans--;
		printf("%lld\n", ans);
	}
	return 0;
}