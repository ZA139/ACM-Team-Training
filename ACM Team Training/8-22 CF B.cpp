#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int A[60][60], B[60][60], ans[10000000][2];
typedef long long int;
int cnt1 = 0, cnt = 0;
int n, m;//paixu
int slove(int x, int y) {
	if (A[x][y] && A[x][y + 1] && A[x + 1][y] && A[x + 1][y + 1]) {//ËÄ¸öÎª1
		ans[cnt1][0] = x;
		ans[cnt1++][1] = y;
		B[x][y] = B[x][y + 1] = B[x + 1][y] = B[x + 1][y + 1] = 1;
	}
	return 0;
}
int main(void) {
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(ans, 0, sizeof(ans));
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			cnt += A[i][j];
		}
	}
	if (cnt == 0) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= m; j++) {
			slove(i, j);
		}
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (A[i][j] != B[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	cout << cnt1 << endl;
	for (int i = 0; i < cnt1; i++)
	{
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	return 0;
}