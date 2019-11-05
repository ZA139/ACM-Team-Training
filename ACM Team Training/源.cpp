#include<cstdio>
#include<algorithm>
using namespace std;
int num[105], ans[105], suf[105];
int main(void) {
	//freopen("txt.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	while (n)
	{
		long long a = 0, b = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			ans[i] = ans[i - 1] + num[i];
		}
		for (int i = n; i > 0; i--)
		{
			suf[i] = suf[i + 1] + num[i];
		}
		int index = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a < ans[i]) {
				index = i;
				a = ans[i];
			}
		}
		int ind = n + 1;
		int cnt = 0;
		for (int i = index + 1; i < n + 1; i++)
		{
			if (b < suf[i]) {
				cnt = 1;
				ind = i;
				b = suf[i];
			}
		}
		while (index + 1 != ind && index != ind)
		{
			if (cnt & 1) {
				index++;
				a += num[index];
				cnt++;
			}
			else {
				ind--;
				b += num[ind];
				cnt++;
			}
		}
		printf("%lld\n", max(a - b, b - a));
		scanf("%d", &n);
	}
	return 0;
}