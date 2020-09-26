#include<cstdio>
#include<algorithm>
int main(void) {
	long long n;
	scanf("%lld", &n);
	while (n--)
	{
		long long a[3], ans = 0;
		scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
		std::sort(a, a + 3);
		a[0]++;
		a[2]--;
		ans = a[2]-a[0]+a[2]-a[1]+a[1]-a[0];
		if (ans >= 0) {
			printf("%lld\n", ans);
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}