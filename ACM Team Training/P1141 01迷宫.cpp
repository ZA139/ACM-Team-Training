#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
short map[1005][1005];
long long ans[1005][1005];
void dfs(int i,int j,int cnt) {
}
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (!ans[i][j]) {
				dfs(i, j, 1);
			}
		}
	}
	return 0;
}