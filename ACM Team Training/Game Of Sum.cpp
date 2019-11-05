#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int S[110], A[110], d[110][110], vis[110][110], n;
int dp(int i, int j) {
	if (vis[i][j])
		return d[i][j];
	vis[i][j] = 1;
	int m = 0;
	for (int k = i+1; k <=j; k++)
	{
		m = min(m, dp(k, j));
	}
	for (int k = i; k < j; k++) {
		m = min(m, dp(i, k));
	}
	d[i][j] = S[j] - S[i - 1] - m;
	return d[i][j];
}
int main(void) {
	while (scanf("%d",&n)&&n)
	{
		S[0] = 0;
		for (int i = 1; i <=n; i++)
		{
			scanf("%d", &A[i]);
			S[i] = S[i - 1] + A[i];
		}
		memset(vis, 0, sizeof(vis));
		printf("%d\n", 2 * dp(1, n) - S[n]);
	}
	return 0;
}