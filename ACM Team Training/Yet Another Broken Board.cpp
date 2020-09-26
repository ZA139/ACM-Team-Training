	#include<iostream>
	#include<cctype>
	#include<string>
	using namespace std;
	string s;
	char s2;
	int app[30];
	int main(void) {
		ios::sync_with_stdio(false);
		int len, k;
		cin >> len >> k;
		cin >> s;
		for (int i = 0; i < k; i++) {
			cin >> s2;
			app[s2 - 'a'] = 1;
		}
		long long lenx = 0;
		long long sum = 0;
		for (int i = 0; i <len; i++) {
			if (app[s[i] - 'a']==1) {
				lenx++;
			}
			else {
				sum += lenx * (lenx + 1) / 2;
				lenx = 0;
			}
		}
		sum += lenx * (lenx + 1) / 2;
		cout << sum << endl;
		return 0;
	}