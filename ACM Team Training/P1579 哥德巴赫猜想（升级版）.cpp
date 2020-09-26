#include<cstdio>
#include<cmath>
#include<cstring>
bool prime[30000];
void slove() {
	int n = 30000;
	int m = sqrt(n);
	memset(prime, 0, sizeof(prime));
	prime[0] = prime[1] = true;
	for (int i = 2; i <= m; i++) {
		if (!prime[i])
		for (int j = i*i; j <= n; j+=i) {
			prime[j] = true;
		}
	}
}
int main(void) {
	slove();
	long long n = 0;
	long long sum = 0;
	scanf("%lld", &n);
	for (int i = 2; i < n; i++) {
		if (!prime[i]) {
			sum += i;
			for (int j = 2; j < n; j++) {
				if (!prime[j]) {
					sum += j;
					if (!prime[n - sum]) {
						printf("%d %d %lld\n", i, j, n - sum);
						return 0;
					}
					sum -= j;
				}
			}
			sum -= i;
		}
	}
	return 0;
}