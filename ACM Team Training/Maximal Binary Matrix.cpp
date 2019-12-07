#include<cstdio>
int ans[105][105];
int main(void) {
	int n, k;
	scanf("%d%d", &n, &k);
	if (k > n*n) {
		printf("-1\n");
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j && k) {
					k--;
					ans[i][i] = 1;
				}
				else if (k > 1&&!ans[i][j]) {
					k -= 2;
					ans[i][j] = ans[j][i] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}