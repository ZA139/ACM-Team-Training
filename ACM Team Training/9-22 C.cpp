#include<cstdio>
int ans[200005];
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		bool flag = true;
		int cnt = 0;
		int l1=0, l2=0;
		long long len;
		scanf("%lld", &len);
		int t;
		for (long long i = 0; i < len; i++)
		{
			scanf("%1d", &t);
			if (t >= l1) {
				l1 = t;
				ans[cnt++] = 1;
			}
			else if (t >= l2) {
				l2 = t;
				ans[cnt++] = 2;
			}
			else
			{
				flag = false;
				printf("-\n");
				break;
			}
		}
		if (flag)
		{
			for (long long i = 0; i < cnt; i++)
			{
				printf("%d", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}