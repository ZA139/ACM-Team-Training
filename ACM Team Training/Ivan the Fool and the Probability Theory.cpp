#include<cstdio>
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
long long f[maxn];
void fun(int max) {
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <=max; i++)
	{
		f[i] = (f[i - 1] + f[i - 2])%mod;
	}
}
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	fun(n>m?n:m);
	printf("%lld\n", (2 * (f[n] + f[m] - 1))%mod);
	return 0;
}