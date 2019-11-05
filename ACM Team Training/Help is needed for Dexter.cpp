#include<cstdio>
long long f(long long n) {
	return n == 1 ? 1 : f(n / 2) + 1;
}
int main(void) {
	long long n;
	while (~scanf("%lld",&n))
	{
		printf("%lld\n", f(n));
	}
	return 0;
}