#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define eps 1e-7
double a, b, c, d;
double func(double x) {
	return a *pow(x,3) + b *pow(x,2) + c * x + d;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c >> d;
	double l, r,ans;
	cin >> l >> r;
	double mid;
	double temp = func(l)*func(r);
	while (l+eps<=r&&temp <=0)
	{
		mid = (l + r) / 2;
		if (func(mid) == 0.0) {
			cout << fixed << setprecision(2) << mid << endl;
			return 0;
		}
		if (func(mid)*func(l) >= 0)
			l = mid;
		else if (func(mid)*func(r) >= 0)
			r = mid;
		temp = func(l)*func(r);
	}
	cout << fixed << setprecision(2) << l << endl;
	return 0;
}