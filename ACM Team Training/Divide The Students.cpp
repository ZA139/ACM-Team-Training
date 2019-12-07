#include<cstdio>
#include<algorithm>
using namespace std;
long long a, b, c,sum;
bool check(long long x) {
	if (sum > 3 * x)
		return false;
	if (a > c) {
		swap(a, c);
	}
	if (x < a)
		return false;
	if (c > 2 * x)
		return false;
	else {
		if (c <= x)
			return true;
		else {
			long long temp = c - x;
			temp = x - temp;
			if (temp < 0) {
				if (a > x)
					return false;
				else
					return true;
			}
			long long bb = b;
			bb -= temp;
			if (a +bb> x) {
				return false;
			}
			else
				return true;
		}
	}
}
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		sum = a + b + c;
		long long left = 0, right = 0x3f3f3f3f3f3f;
		while (left <= right) {
			long long mid = (left + right) >> 1;
			if (check(mid)) {
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		printf("%lld\n", left);
	}
	return 0;
}