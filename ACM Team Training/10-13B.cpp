#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string s;
int main(void) {
	long long t, n;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		cin >> n;
		long long ac = 0, temp = 0;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1') {
				ac = i + 1;
			}
		}
		for (long long i = 0; i < n; i++)
		{
			if (s[n - i - 1] == '1') {
				ac = max(ac, i + 1);
			}
		}
		if (ac == 0) {
			cout << n << endl;
		}
		else {
			cout << max(2 * ac, n) << endl;
		}
	}
	return 0;
}