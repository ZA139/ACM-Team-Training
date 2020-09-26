#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
const int INF = 99999999;
short zhangwentaodashuaibi[10005][10005];
bool map[10005];
int dis[10005];
int ans = INF;
int temp = 0;
bool flag = 0;
int n,b;
using namespace std;
void dfs(int a) {
	if (!ans)
		return;
	map[a] = 1;
	if (a == b) {
		ans = min(ans, temp);
		flag = 1;
		return;
	}
	for (int i = 1; i <=n; i++)
	{
		if (zhangwentaodashuaibi[a][i] == 0&&!map[i]) {
			dfs(i);
			map[i] = 0;
		}
		else if (zhangwentaodashuaibi[a][i] == 1 && !map[i]) {
			temp += 1;
			dfs(i);
			map[i] = 0;
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
			zhangwentaodashuaibi[i][j] == 999;
	}
	for (int i = 0; i <=n; i++)
	{
		dis[i] = 999;
	}
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n; i++)
	{ 
		int t;
		scanf("%d", &t);
		int j;
		t=t - 1;
		scanf("%d", &j);
		zhangwentaodashuaibi[i][j] = 0;
		while (t--)
		{
			scanf("%d", &j);
			zhangwentaodashuaibi[i][j] = 1;
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