#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long nums[1000005],sum,temp[1000005];
int main(void) {
	int n;
	while (~scanf("%d",&n))
	{
		memset(nums, 0, sizeof(nums));
		unsigned long long sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &nums[i]);
			sum += nums[i];
		}
		long long M = sum / n;
		long long ans = 0;
		temp[0] = 0;
		for (int i = 1; i <= n; i++) {
			temp[i] = nums[i] + temp[i - 1] - M;
		}
		sort(temp, temp + n);
		long long mid = 0;
		if (n & 1) {
			mid = temp[n / 2];
		}
		else {
			mid = (temp[n / 2] + temp[n / 2 - 1]) / 2;
		}
		for (int i = 0; i < n; i++)
		{
			ans += abs(mid - temp[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}