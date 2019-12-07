#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int dp[30][200005];
string s,s1;
int len;
bool check(int x) {
	int cn[30];
	memset(cn, 0, sizeof(cn));
	int len1 = s1.length();
	for (int i = 0; i < len1; i++) {
		cn[s1[i] - 'a']++;
	}
	for (int i = 0; i < 30; i++) {
		if (cn[i] > dp[i][x]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> len;
	cin >> s;
	int t;
	for (int i = 1; i <=len; i++) {
		for (int j = 0; j < 28; j++) {
			dp[j][i] = dp[j][i - 1];
		}
		dp[s[i-1] - 'a'][i]++;
	}
	cin >> t;
	while (t--)
	{
		cin >> s1;
		int left = 0, right = len;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (check(mid)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		cout << left << endl;
	}
	return 0;
}