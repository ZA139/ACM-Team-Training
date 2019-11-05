#include<cstdio>
#include<algorithm>
#include<cstring>
const int INF = 0x3f3f3f3f;
using namespace std;
int o[16][16], a[16][16],n;
int slove(int s) {
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		if (s&(1 << i)) {
			a[0][i] = 1;
		}
		else if (o[0][i] == 1)
			return INF;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			int sum = 0;
			if (i > 1) {
				sum += a[i - 2][j];
			}
			if (j > 0) {
				sum += a[i - 1][j - 1];
			}
			if (j + 1 < n)
				sum += a[i - 1][j + 1];
			a[i][j] = sum % 2;
			if (o[i][j] == 1 && a[i][j] == 0) {
				return INF;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (a[i][j] != o[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main(void) {
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++)
	{
		int ans = INF;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				scanf("%d", &o[i][j]);
			}
		}
		for (int i = 0; i <(1<<n); i++)
		{
			ans=min(ans,slove(i));
		}
		if (ans == INF)ans = -1;
		printf("Case %d: %d\n",i+1,ans);
	}
	return 0;
}