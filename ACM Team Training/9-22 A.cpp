#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[105];
bool vis[105];
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &num[i]);
		vis[num[i]] = true;
	}
	long long ans =0;
	sort(num, num + t);
	for (int i = 0; i < t; i++)
	{
		if (vis[num[i]]) {
			vis[num[i]] = false;
			ans++;
		}
		for (int j = 2; j*num[i] <= 100; j++)
		{
			if (vis[num[i] * j]) {
				vis[num[i] * j] = false;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}