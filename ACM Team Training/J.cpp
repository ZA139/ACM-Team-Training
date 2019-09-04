#include<cstdio>
int main(void) {
	int t;
	long long ans = 0;
	scanf("%d", &t);
	for (int i = 1;; i++)
	{
		t--;
		ans += (i*t);
		if (t == 0) {
			ans += i;
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}