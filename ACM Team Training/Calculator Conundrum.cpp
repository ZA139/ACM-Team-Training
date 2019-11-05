	#include<cstdio>
	#include<algorithm>
	long long n, k;
	long long next(long long lim,long long base) {
		long long temp = base * base;
		while (temp>=lim)
		{
			temp /= 10;
		}
		return temp;
	}
	int main(void) {
		int t;
		scanf("%d", &t);
		while (t--) {
			scanf("%lld%lld", &n, &k);
			long long ans = k;
			long long k1=k,k2=k;
			long long lim = 1;
			while (n--)
			{
				lim *= 10;
			}
			do {
				k1 = next(lim,k1);
				ans = std::max(ans, k1);
				k2 = next(lim,k2);
				ans = std::max(ans, k2);
				k2 = next(lim,k2);
				ans = std::max(ans, k2);
			} while (k1 != k2);
			printf("%lld\n", ans);
		}
		return 0;
	}