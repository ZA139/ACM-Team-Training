#include<iostream>
#include<cstdio>
using namespace std;
int main(void) {
	long long t;
	cin >> t;
	while (t--) {
		long long a, b, c, d, k;
		ios::sync_with_stdio(false);
		cin >> a >> b >> c >> d >> k;
		long long a1 = a / c;
		if (a%c != 0)
			a1++;
		long long a2 = b / d;
		if (b%d != 0)
			a2++;
		if (a1 + a2 > k) {
			cout << "-1" << endl;
		}
		else
			cout << a1 << " " << a2 << endl;
	}
	return 0;
}