#include<iostream>
using namespace std;
int a[15000];
int cnt =1;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < t; i++) {
		if (a[i] & 1) {
			cout << (a[i] + cnt) / 2 << endl;
			cnt *= -1;
		}
		else
			cout << a[i] / 2 << endl;
	}
	return 0;
}