#include<cstdio>
long sigama(long a) {
	return a+a * (a - 1) / 2;
}
int main(void) {
	long a, b,t;
	scanf("%ld", &t);
	while (t--)
	{
		scanf("%ld%ld", &a, &b);
		printf("%ld\n", sigama(a)*sigama(b));
	}
	return 0;
}