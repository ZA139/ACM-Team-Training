#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(void) {
	int t;
	cin >> t;
	int ans = 0;
	while (t--) {
		string s;
		cin >> s;
		if (s.length() >= 5) {
			string sub = s.substr(s.length() - 5);
			if (sub == "acpty") {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}