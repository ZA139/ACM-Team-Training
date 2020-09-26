#include<cstdio>
#include<cmath>
const long long mod = 1e9 + 7;
long long ans[1000005];
long long prime[1000005];//素数数组
bool is_prime[1000005 + 10];//is_pri[i]表示i是素数
inline long long slove(long long k) {
	if (is_prime[k]) {
		return ((1 + k) / 2) % mod;
	}
	long long temp = sqrtl(k);
	if (temp*temp == k) {
		return temp % mod;
	}
	else {
		for (long long i = temp; i > 1; i--) {
			if (k%i == 0) {
				return ((temp + k / temp) / 2) % mod;
			}
		}
	}
}
//返回n以内素数的个数
int sieve(long long n)
{
	int p = 0;//素数个数计数器
	for (int i = 0; i <= n; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;//首先标记0和1不是素数
	is_prime[2] = true;//标记2是素数

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (is_prime[i]) //如果i是素数
		{
			prime[++p] = i;//将素数放进素数表
			for (int j = i * i; j <= n; j += 2 * i)//所有i的倍数都不是素数
				is_prime[j] = false;
		}
	}
	return p;
}
int main(void) {
	//sieve(1000005);
	for (long long i = 0; i < 1000001; i++) {
		ans[i] = ans[i - 1] + slove(i);
		ans[i] %= mod;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}