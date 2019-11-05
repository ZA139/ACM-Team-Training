//#include<stdio.h>
//struct Matrix {
//	long long data[2][2];
//}ans1, ans;
//Matrix mul(Matrix a, Matrix b) {
//	Matrix temp;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int k = 0; k < 2; k++)
//			temp.data[i][k] = 0;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			for (int k = 0; k < 2; k++)
//			{
//				temp.data[i][j] += (a.data[i][k] * b.data[k][j])%10000;
//			}
//		}
//	}
//	return temp;
//}
//
//void QuickPower(int N) {
//	ans.data[0][0] = ans.data[0][1] = ans.data[1][0] = 1;
//	ans.data[1][1] = 0;
//
//	ans1.data[0][0] = ans1.data[0][1] = ans1.data[1][0] = 1;
//	ans1.data[1][1] = 0;
//	while (N)
//	{
//		if (N & 1)
//			ans1 = mul(ans1, ans);
//		ans = mul(ans, ans);
//		N >>= 1;
//	}
//}
//int main(void) {
//	long long a;
//	scanf("%lld", &a);
//	while (a != -1)
//	{
//		if (a == 0)
//			printf("0\n");
//		else
//		{
//			QuickPower(a-1);
//			printf("%d\n", ans1.data[0][1] % 10000);
//		}
//		scanf("%lld", &a);
//	}
//	return 0;
//}
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 200 + 13;
const int INF = 1e9;

int n, k;
int a[N];
vector<int> g[N];
int dp[N][N];
int d[N];
int tmp[N];

void dfs(int v, int p = -1) {
	d[v] = 1;
	dp[v][0] = a[v];
	for (auto u : g[v]) if (u != p) {
		dfs(u, v);
		int nw = max(d[v], d[u] + 1);
		forn(i, nw)
			tmp[i] = -INF;
		forn(i, d[v]) for (int j = max(0, k - i); j < d[u]; ++j)
			tmp[min(i, j + 1)] = max(tmp[min(i, j + 1)], dp[v][i] + dp[u][j]);
		forn(i, d[u])
			tmp[i + 1] = max(tmp[i + 1], dp[u][i]);
		forn(i, d[v])
			dp[v][i] = max(dp[v][i], tmp[i]);
		for (int i = d[v]; i < nw; ++i)
			dp[v][i] = tmp[i];
		d[v] = nw;
		for (int i = d[v] - 1; i > 0; --i)
			dp[v][i - 1] = max(dp[v][i - 1], dp[v][i]);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	printf("%d\n", dp[0][0]);
}
