#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll fish[100005];
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll ans = 0;
		ll pr, n;
		for (ll i = 0; i < n; i++)
		{
			scanf("%lld", &fish[i]);
			ans += fish[i];
		}
		sort(fish, fish + n);
		ans -= fish[0];
		ans += k;
	}
	return 0;
}