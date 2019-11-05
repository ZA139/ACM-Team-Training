#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const double eps = 1e-7;
int num[10];
double a[10], b[10];
int t;
bool check(double x) {
	double temp =a[num[0]];
	for (int i = 1; i < t; i++) {
		if (temp + x > b[num[i]]) {
			return false;
		}
		temp += x;
		temp = max(temp, a[num[i]]);
	}
	return true;
}
int main(void) {
	//freopen("txt.txt", "w", stdout);
	int cnt = 1;
	double ans = 0;
	while (scanf("%d", &t) && t)
	{
		ans = 0;
		memset(num, 0, sizeof(num));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < t; i++) {
			scanf("%lf%lf", &a[i],&b[i]);
			num[i] = i;
		}
		do {
			double l = 0, r = 100000;
			while (l + eps < r)
			{
				double mid = (l + r) / 2;
				if (check(mid)) {
					l = mid;
				}
				else
					r = mid;
			}
			ans = max(ans, r);
		}while (next_permutation(num,num + t));
		ans *= 60;
		printf("Case %d: %d:%02d\n", cnt++, (int)ans / 60, (int)(fmod(ans, 60) + 0.5));
	}
	return 0;
}