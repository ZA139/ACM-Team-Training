#include<cstdio>
int main(void) {
	long long n, t, sum = 0;
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++)
	{
		scanf("%1lld", &t);
		if (t % 2 == 0) {
			sum++;
			sum += i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}