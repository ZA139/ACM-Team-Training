#include<iostream>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(void) {
	ios::sync_with_stdio(false);
	long long T, a, b, c, d,e,f;
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c >> d;
		f = b * d;
		e = a * d + b *c;
		long long ass = gcd(e, f);
		f /= ass;
		e /= ass;
		cout << e <<" "<< f << endl;
	}
	return 0;
}