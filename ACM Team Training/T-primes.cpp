#include<iostream>
using namespace std;
#define maxn 1000050
bool judge[maxn];
	int main(void) {
		memset(judge, 0, sizeof(judge));
		int m = sqrt(maxn + 0.5);
		for (long long i = 2; i < m; i++)
		{
			if (!judge[i])
				for (long long j = i * i; j <= maxn; j += i)judge[j] = i;
		}
		judge[1] = judge[0] = 1;
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		int t;
		bool ans = true;
		cin >> t;
		while (t--)
		{
			long long a;
			cin >> a;
			long long b = sqrtl(a)+0.9999999;
			if (!judge[b]&&b==sqrtl(a))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		return 0;
	}