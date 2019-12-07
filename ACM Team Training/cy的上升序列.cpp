#include<cstdio>
long long dp[4000][4000];
const long long mod = 998244353;
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	for (long long i = 1; i <= m; i++) {
		dp[i][1] = 1;
	}
	for (long long i = 1; i <= n; i++) {
		dp[m][i] = 1;
	}
	for (long long j = m - 1; j > 0; j--) {
		for (long long i = 2; i <= n; i++) {
			dp[j][i] = (dp[j + 1][i]) % mod + (dp[j][i - 1]) % mod;
			dp[j][i] %= mod;
		}
	}
	long long ans = 0;
	for (long long i = 1; i <= m; i++) {
		ans += dp[i][n];
		ans %= mod;
	}
	printf("%lld\n", ans%mod);
	return 0;
}