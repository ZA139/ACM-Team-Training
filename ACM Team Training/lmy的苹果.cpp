#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
long long ksm(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b % 2 == 1) {
			ans *= a;
		}
		a *= a;
		b /= 2;
	}
	return ans;
}
int main(void) {
	long long t, n;
	scanf("%lld", &t);
	while (t--) {
		int cnt = -1;
		long long ans = 1;
		scanf("%lld", &n);
		while (n) {
			cnt++;
			n /= 2;
		}
		ans = ksm(2, cnt);
		printf("%lld\n", ans);
	}
	return 0;
}