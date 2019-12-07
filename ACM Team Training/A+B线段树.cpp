#include <cstdio>
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
#define maxn 400005
struct Matrix {
	long long data[2][2];
}ans1, ans;
Matrix mul(Matrix a, Matrix b) {
	Matrix temp;
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
			temp.data[i][k] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				temp.data[i][j] += (a.data[i][k] * b.data[k][j]) % 10000;
			}
		}
	}
	return temp;
}

void QuickPower(int N) {
	ans.data[0][0] = ans.data[0][1] = ans.data[1][0] = 1;
	ans.data[1][1] = 0;

	ans1.data[0][0] = ans1.data[0][1] = ans1.data[1][0] = 1;
	ans1.data[1][1] = 0;
	while (N)
	{
		if (N & 1)
			ans1 = mul(ans1, ans);
		ans = mul(ans, ans);
		N >>= 1;
	}
}
int a[maxn];
int num[1000010];
int vis[maxn];
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		int kk = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int temp = a[1];
		int s = 1;
		for (int i = 2; i <= n; i++)
		{
			if (temp == a[i])
			{
				s++;
			}
			else
			{
				temp = a[i];
				num[kk++] = s;
				s = 1;
			}
		}
		int ans1 = 0;
		int ans2 = 0;
		int ans3 = 0;
		ans1 = num[0];
		int i = 1;
		while (ans2 <= ans1 && i < kk)
		{
			ans2 += num[i];
			i++;
		}
		if (i == kk)
		{
			cout << "0 0 0" << endl;
			continue;
		}
		while (i < kk && ans3 + num[i] <= n / 2 - ans2 - ans1)
		{
			ans3 += num[i];
			i++;
		}

		if (ans3 > ans1 && ans1 + ans2 + ans3 <= n / 2)
		{
			cout << ans1 << ans2 << ans3 << endl;
		}
		else {
			cout << "0 0 0" << endl;
		}
	}
	return 0;
}
