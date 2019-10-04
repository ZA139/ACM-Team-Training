#include<cstdio>
#include<cstring>
long long nums[1005];
long long cnt[2050];
long long pow(int i, int n) {
	long long ans = 1;
	while (n--)
	{
		ans *= i;
	}
	return ans;
}
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(nums, 0, sizeof(nums));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld",&nums[i]);
			if (nums[i] <= 2048)
				cnt[nums[i]]++;
		}
		int cnn = 0;
		for (int i = 0; i <=11; i++)
		{
			cnt[pow(2, i)] += cnn;
			cnn = cnt[pow(2, i)] / 2;
		}
		if (cnt[2048])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}