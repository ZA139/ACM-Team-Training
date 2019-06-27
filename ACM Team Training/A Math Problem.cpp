#include<stdio.h>
int main(void) {
	long long n, counts = 0;
	scanf("%lld", &n);
	//long double temp = sqrt(n);
	for (long long i = 1;; i++)
	{
		for (long long j = 1; j <= i; ++j)
		{
			n /= i;
		}
		if (n == 0)
		{
			break;
		}
		else
		{
			counts++;
		}
	}
	printf("%lld\n", counts);
	return 0;
}