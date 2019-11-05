#include<cstdio>
int main(void) {
	int t;
	char ch;
	scanf("%d", &t);
	getchar();
	long long ans = 0;
	while (t--)
	{
		ch = getchar();
		if (ch == 'G') {
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}