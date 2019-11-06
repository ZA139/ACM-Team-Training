#include<cstdio>
int main(void) {
	int n;
	scanf("%d", &n);
	long long a, b, c, d;
	while (n--) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		bool ans = false;
		a *= c;
		if (a > d) {
			d %= c;
			if (b >= d) {
				ans = true;
			}
		}
		else if (a == d) {
			ans = true;
		}
		else {
			d -= a;
			if (b >= d) {
				ans = true;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}