#include<cstdio>
#include<algorithm>
const int maxn = 10 + 5;
char map[maxn][maxn];
int main(void) {
	freopen("txt.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		memset(map, 0, sizeof(map));
		int n;
		scanf("%d", &n);
		getchar();
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++) {
				scanf("%c", &map[j][k]);
			}
			getchar();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == '.') {
					for (char ch = 'A'; ch <= 'Z'; ch++) {
						bool ok = true;
						if (i > 0 && map[i - 1][j] == ch)ok = false;
						if (i < n - 1 && map[i + 1][j] == ch)ok = false;
						if (j > 0 && map[i][j - 1] == ch)ok = false;
						if (j < n - 1 && map[i][j + 1] == ch)ok = false;
						if (ok) {
							map[i][j] = ch;
							break;
						}
					}
				}
			}
		}
		printf("Case %d:\n", cas);
		for (int i = 0; i < n; i++)printf("%s\n", map[i]);
	}
	return 0;
}