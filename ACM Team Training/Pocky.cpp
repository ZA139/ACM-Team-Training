#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
using namespace std;
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		double l, d;
		cin >> l >> d;
		if (l <= d) {
			cout << "0.000000" << endl;
			continue;
		}
		else {
			double ans = log(l) - log(d)+1;
			printf("%.6f\n", ans);
		}
	}
	return 0;
}