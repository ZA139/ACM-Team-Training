#include<iostream>
#include<string>
using namespace std;
string s1, s2;
typedef unsigned long long ull;
const ull B = 100000007;
bool contain(string a, string b) {
	long long a1 = a.length();
	long long b1 = b.length();
	ull t = 1;

	for (long long i = 0; i < a1; i++) {
		t *= B;
	}

	ull ah = 0, bh = 0;
	for (long long i = 0; i < a1; i++) {
		ah = ah * B + a[i];
	}

	for (long long i = 0; i < a1; i++) {
		bh = bh * B + b[i];
	}

	for (long long i = 0; i + a1 <= b1; i++) {
		if (ah == bh)
			return true;
		if (i + a1 < b1) {
			bh = bh * B + b[i + a1] - b[i] * t;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> s1;
	cin >> s2;
	if (s1 == s2) {
		cout << "Yes" << endl;
		return 0;
	}
	else if (s1.length() < s2.length()) {
		cout << "No" << endl;
	}
	else {
		s1.append(s1);
		if (contain(s2, s1)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}