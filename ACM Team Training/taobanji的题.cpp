#include<cstdio>
#include<iostream>
using namespace std;
int map[330][330];
int cnt = 0;
int vis[330][330];
int n, m;
int dis[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int dfs(int x, int y) {
	if (x >= n || y >=  m|| x < 0 || y < 0) return 0;
	if (map[x][y] == 0) return 0;
	if (vis[x][y]) return 0;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		 dfs(x + dis[i][0], y + dis[i][1]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int dx, dy, nx, ny;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d%d", &dx, &dy, &nx, &ny);
		for (int i = dx - 1; i < nx; i++) {
			for (int j = dy - 1; j < ny; j++) {
				map[i][j] = 1;
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && map[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}