//#include<cstdio>
//#include<algorithm>
//#include<cmath>
//long long ans[2];
//long long mi = 0x3f3f3f3f3f3f3f;
//int main(void) {
//	long long a, b, c=0, d;
//	scanf("%lld%lld", &a, &b);
//	long long sum = a * b;
//	d = sum;
//	bool first = 0;
//	while (1)
//	{
//		if (!first) {
//			first = 1;
//			c = (long long)(sqrtl(sum))+1;
//		}
//		if (sum%c == 0) {
//			d = sum / c;
//			if (c + d < mi) {
//				ans[0] = c;
//				ans[1] = d;
//				break;
//			}
//		}
//		c--;
//	}
//	printf("%lld %lld", ans[0], ans[1]);
//	return 0;
//}
#include<iostream>
using namespace std;
long long gcd(long long a, long long b) {
	return a % b == 0 ? b : gcd(b, a%b);
}
int main(void) {
	long long a, b,di;
	ios::sync_with_stdio(false);
	cin >> a >> b;
	di = gcd(a, b);
	long long lcm = a * b / di;
	cout << lcm / a << " " << lcm / b << endl;
	return 0;
}