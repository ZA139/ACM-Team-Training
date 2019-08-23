#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll ans = 0;
		ll b, p, f;
		scanf("%lld%lld%lld", &b, &p, &f);
		ll p1, p2;
		scanf("%lld%lld", &p1, &p2);
		if (p1 < p2) {
			swap(p, f);
			swap(p1, p2);
		}
		while (p--) {
			b -= 2;
			if (b >= 0)
				ans += p1;
			else
				break;
		}
		while (f--)
		{
			b -= 2;
			if (b >= 0)
				ans += p2;
			else
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}