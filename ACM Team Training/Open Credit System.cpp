#include<cstdio>
#include<algorithm>
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		long long ma=-150005,ans=-99999999;
		long long tt;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &tt);
			if (i > 0) {
				ans = max(ans, ma -tt);
			}
			ma = max(ma, tt);
		}
		ans = max(ans, ma - mi);
		printf("%lld\n", ans);
	}
	return 0;
}