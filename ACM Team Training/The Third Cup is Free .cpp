#include<stdio.h>
int n[1050];
int main(void) {
	int T, k = 1,a;
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0, cnt = 0,cups;
		scanf("%lld", &cups);
		for (int i = 0; i < cups; i++)
		{
			scanf("%d",&a);
			n[a]++;
		}
		for (int i=1000;i>0;i--)
		{
			while (n[i])
			{
				cnt++;
				if (!(cnt % 3))
					cnt = 0;
				else ans += i;
				n[i]--;
			}
		}
		printf("Case #%d: %lld\n", k++, ans);
	}
	return 0;
}