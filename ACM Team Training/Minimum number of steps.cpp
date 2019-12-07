#include<iostream>
#include<string>
const long long mod = 1e9 + 7;
using namespace std;
int main(void) {
	string s;
	cin >> s;
	long long ans = 0, cnt = 0;
	int len = s.size();
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] == 'b') {
			cnt++;
		}
		else {
			ans += cnt;
			cnt *= 2;
			cnt %= mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}