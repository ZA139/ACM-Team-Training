#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int ans[maxn][maxn];
int quick_pow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;

		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}
void dfs(int n, int x, int y, int cnt) {
	if (n == 0) {
		ans[x][y] = cnt;
		return;
	}
	int now = quick_pow(2, n - 1);
	dfs(n - 1, x, y, cnt);
	dfs(n - 1, x, y + now, cnt);
	dfs(n - 1, x + now, y, -cnt);
	dfs(n - 1, x + now, y + now, cnt);
}
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int N = quick_pow(2, n), cnt = 1;
		//cout << N << endl;
		dfs(n, 1, 1, cnt);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (ans[i][j] == 1) {
					cout << "C";
				}
				else if (ans[i][j] == -1) {
					cout << "P";
				}
			}
			cout << endl;
		}
	}


	//system("pause");
	return 0;
}