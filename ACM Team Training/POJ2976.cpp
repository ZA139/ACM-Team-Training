#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;
const long double eps = 1e-7;
typedef struct ass {
	long long a;
	long long b;
}ass;
bool cmp(long double a, long double b) {
	return a > b;
}
long long n, k;
ass temp[10000];
long double tt[10000];
bool check(long double x) {
	for (int i = 0; i < n; i++) {
		tt[i] = (long double)temp[i].a - x*(temp[i].b);
	}
	sort(tt, tt + n, cmp);
	long double sum = 0;
	for (int i = 0; i < n - k; i++) {
		sum += tt[i];
	}
	return sum+eps >= 0;
}
int main(void) {
	while (scanf("%lld%lld", &n, &k) && !(n == 0&& k == 0)) {
		for (int i = 0; i < n; i++) {
			scanf("%lld", &temp[i].a);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &temp[i].b);
		}
		long double left = 0.0;
		long double right = 0x3f3f3f3f3f3f;
		while (left + eps < right)
		{
			long double mid = (left + right) / 2.0;
			if (check(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		printf("%.0lf\n", left * 100);
	}
	return 0;
}