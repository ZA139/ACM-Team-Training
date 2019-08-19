#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long prime[1000010], max = 0, cnt = 1, beauty[1000010], ans[1000010];
int t, b;
inline void isprime() {
	int n = sqrt(1000010 + 0.5);
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			for (int j = i * i; j <= 1000010; j += i)
				prime[j] = 1;
		}
	}
	return;
}
void slove(long long a) {
	long long sum = 0;
	long long temp = a;
	while (a)
	{
		sum += a % 10;
		a /= 10;
	}
	if (!prime[sum])
	{
		beauty[temp] = 1;
	}
	return;
}
int main(void) {
	memset(prime, 0, sizeof(prime));
	memset(beauty, 0, sizeof(beauty));
	memset(ans, 0, sizeof(ans));
	int t;
	isprime();
	prime[1] = 1;
	scanf("%d", &t);
	for (long long i = 1; i <= 1000010; i++)
	{
		if (!prime[i])
		{
			slove(i);
		}
	}
	long long cnt1 = 0;
	for (long long i = 1; i <= 1000010; i++)
	{
		if (beauty[i])
		{
			cnt1++;
		}
		ans[i] = cnt1;
	}
	ans[1] = 0;
	while (t--)
	{
		long long l, r;
		scanf("%lld%lld", &l, &r);
		printf("Case #%lld: %lld\n", cnt++, ans[r] - ans[l - 1]);
	}
	return 0;
}
//二筛一打表