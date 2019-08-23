#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int A[60][60], B[60][60], ans[111][2];
typedef long long ll;
ll cnt1 = 0, cnt = 0;
int n, m;//paixu
int slove(int x, int y) {
	if (!cnt) {
		return 1;
	}
	else if (A[x][y] && A[x][y + 1] && A[x + 1][y] && A[x + 1][y + 1]) {//四个为1
		ans[cnt1][0] = x;
		ans[cnt1++][1] = y;
		cnt -= 4;
		B[x][y] = B[x][y + 1] = B[x + 1][y] = B[x + 1][y + 1] = 1;
	}
	//左列为1
	else if (A[x][y] && A[x + 1][y] && !A[x][y + 1] && !A[x + 1][y + 1] && y - 1 > 0 && A[x][y - 1] && A[x + 1][y - 1]) {
		ans[cnt1][0] = x;
		ans[cnt1++][1] = y - 1;
		B[x][y] = B[x + 1][y] = 1;
		cnt -= 2;
	}
	else if (A[x][y] && A[x][y + 1] && !A[x + 1][y] && !A[x + 1][y + 1] && A[x - 1][y] && A[x - 1][y + 1]) {
		ans[cnt1][0] = x - 1;
		ans[cnt1++][1] = y;
		B[x][y] = B[x][y + 1] = 1;
	}
	else if (A[x][y] && A[x + 1][y] && !A[x][y + 1] && !A[x + 1][y + 1] && !A[x][y - 1] && !A[x + 1][y - 1]) {
		cout << "-1" << endl;
		return -1;
	}
	else if (A[x][y] && !A[x][y + 1] && !B[x][y]) {///单个x出现
		if (A[x - 1][y - 1] && A[x - 1][y] && A[x][y - 1]) {
			ans[cnt1][0] = x - 1;
			ans[cnt1++][1] = y - 1;
			B[x][y] = 1;
		}
		else
		{
			cout << "-1" << endl;
			return -1;
		}
	}
	if (y + 2 <= m) {
		return slove(x, y + 2);
	}
	return 0;
	/*if (A[x][y] && A[x][y + 1] && !A[x + 1][y] && !A[x + 1][y + 1]) {
		ans[cnt][0]=
	}*/

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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (A[i][j] != B[i][j]) {
				int o = slove(i, j);
				if (o == -1)
					return 0;
				if (o == 1)
					break;
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