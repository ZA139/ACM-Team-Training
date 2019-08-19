#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long dp[1000005];
int n, m;
bool judge(long long x)
{
	int a, b;
	while (x)
	{
		a = x % 10;
		b = x / 10 % 10;
		if ((a == 2 && b == 6)||a == 4 || b == 4)//×ó»¬ÅÐ¶Ï
			return false;
		x = x / 10;
	}
	return true;
}
int main(void)
{
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 3;
	for (int i = 5; i < 1000005; i++)
	{
		if (judge(i))//¿ÉÒÔÓÃ dp++
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = dp[i - 1];
	}
	scanf("%d%d", &n, &m);
	while (1)
	{
		if (n == 0 && m == 0)
			break;
		if (n > m){
			int t = n;
			n = m;
			m = t;
		}
		if (judge(n))
			printf("%lld\n", dp[m] - dp[n] + 1);
		else
			printf("%lld\n", dp[m] - dp[n]);
		scanf("%d%d", &n, &m);
	}
	return 0;
}