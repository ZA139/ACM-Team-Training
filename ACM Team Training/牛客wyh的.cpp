#include<cstdio>
#include<algorithm>
using namespace std;
#define eps 1e-7
int n, k;
double a[100005], b[100005];
double tt[100005];
bool cmp(double a, double b) {
	return a > b;
}
bool check(double x) {
	for (int i = 0; i < n; i++) {
		tt[i] = a[i] - x * b[i];
	}
	sort(tt, tt + n, cmp);
	double sum = 0;
	for (int i = 0; i < k; i++) {
		sum += tt[i];
	}
	return sum>= 0;
}
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &a[i], &b[i]);
		}
		double left = 0, right = 0x3f3f3f3f3f3f;
		while (left + eps < right) {
			double mid = (left + right) / 2.0;
			if (check(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		printf("%.2lf\n", left);
	}
	return 0;
}