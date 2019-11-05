#include<cstdio>
#include<algorithm>
using namespace std;
long long num[100005];
int main(void) {
	long long s, ans;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		bool flag = false;
		ans = 99999999999999;
		long long n;
		scanf("%lld%lld", &n, &s);
		for (long long i = 0; i < n; i++)
		{
			scanf("%lld", &num[i]);
		}
		long long right = 0, left = 0, sum = 0;
		while (right <= n)
		{
			if (sum < s) {
				sum += num[right];
				right++;
			}
			else {
				flag = true;
				ans = min(ans, right - left);
				sum -= num[left];
				left++;
			}
		}
		if (!flag)
			ans = 0;
		printf("%lld\n", ans);
	}
	return 0;
}