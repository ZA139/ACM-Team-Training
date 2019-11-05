#include<cstdio>
#include<algorithm>
using namespace std;
int head[20005], cas[20005];
int main(void) {
	long long n, m;
	while (scanf("%lld%lld",&n,&m)&&(n&&m))
	{
		for (long long i = 0; i < n; i++)
		{
			scanf("%d", &head[i]);
		}
		for (long long i = 0; i < m; i++)
		{
			scanf("%d", &cas[i]);
		}
		sort(head,head + n);
		sort(cas, cas + m);
		long long cnt = 0,ans=0;
		int j = 0;
		while (cnt < n) {
			for (int i = 0; i <n; i++)
			{
				for (; j < m; j++) {
					if (head[i] <= cas[j]) {
						ans += cas[j];
						j++;
						cnt++;
						break;
					}
				}
			}
			break;
		}
		if (cnt == n) {
			printf("%lld\n", ans);
		}
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}