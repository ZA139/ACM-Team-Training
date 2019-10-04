#include<cstdio>
#include<cstring>
int nums[100005];
int ss[100005];
int main(void) {
	long long n,m,sum = 0;
	int t;
	scanf("%d", &t);
	memset(ss, 0, sizeof(ss));
	while (t--)
	{
		sum = 0;
		scanf("%lld%lld", &n, &m);
		for (int  i = 0; i <n; i++)
		{
			scanf("%d", &nums[i]);
			sum += nums[i];
			ss[i] = sum;
			if (nums[i] >= m) {
				printf("1\n");
				goto x;
			}
		}
		for (int i = 1; i <n; i++)
		{
			for (int j = 0; j+i < n; j ++) {
				if (ss[j + i] - ss[j] >= m)
				{
					printf("%d\n", i);
					goto x;
				}
			}
		}
	x:
		sum = 0;
	}
	return 0;
}