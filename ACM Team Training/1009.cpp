#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
const int INF = 99999999;
short map[10005][10005];
bool vis[10005];
int dis[10005];
int ans = INF;
int temp = 0;
bool flag = 0;
int n,b;
using namespace std;
void dfs(int a) {
	if (!ans)
		return;
	vis[a] = 1;
	if (a == b) {
		ans = min(ans, temp);
		flag = 1;
		return;
	}
	for (int i = 1; i <=n; i++)
	{
		if (map[a][i] == 0&&!vis[i]) {
			dfs(i);
			vis[i] = 0;
		}
		else if (map[a][i] == 1 && !vis[i]) {
			temp += 1;
			dfs(i);
			vis[i] = 0;
			temp -= 1;
		}
	}
	return;
}
int main(void) {
	int a;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			map[i][j] == 999;
	}
	for (int i = 0; i <=n; i++)
	{
		dis[i] = 999;
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{ 
		int t;
		scanf("%d", &t);
		int j;
		t=t - 1;
		scanf("%d", &j);
		map[i][j] = 0;
		while (t--)
		{
			scanf("%d", &j);
			map[i][j] = 1;
		}
	}
	dfs(a);
	x:
	if (!flag)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}