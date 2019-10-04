#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[200005]; 
long long b[200005];
long long len;
void swap1(long long *x, long long *y)
{
	long long t = *x;
	*x = *y;
	*y = t;
}
long long Greatest_common_divisor(long long a, long long b)
{
	if (a < b)
	{
		swap1(&a, &b);
	}
	if (!b)
		return a;
	a = abs(a);
	b = abs(b);
	while (b)
	{
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main(void)
{
	scanf("%lld", &len);
	long long ma = 0;
	for (long long i = 0; i < len; i++)
	{
		scanf("%lld", &b[i]);
		ma = max(ma, b[i]);
	}
	long long cnt = 0;
	for (long long i = 0; i < len; i++)
	{
		cnt -= b[i];
		a[i] = ma - b[i];
	}
	cnt += ma * len;
	long long gcd = Greatest_common_divisor(a[0], a[1]);
	for (long long i = 2; i < len; i++)
	{
		gcd = Greatest_common_divisor(gcd, a[i]);
	}
	printf("%lld %lld\n", cnt / gcd, gcd);
	return 0;
}