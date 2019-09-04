#include<cstdio>
int main(void) {
	int n, m;
	int ans = 0;
	scanf("%d%d", &n, &m);
	while (m != n) {
		if (m & 1 || m < n) {
			ans++;
			m++;
		}
		if (m > n) {
			m /= 2;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}