#include<cstdio>
#include<algorithm>
using namespace std;
int main(void) {
	int l, r, n;
	double mid;
	scanf("%d", &n);
	scanf("%d", &l);
	double temp;
	int index=n/2;
	if (n & 1) {
		index++;
		for (int i = 2; i < n ; i++)
		{
			if (i == index)
				scanf("%lf", &mid);
			else
				scanf("%lf", &temp);
		}
	}
	else {
		for (int i = 2; i < n; i++)
		{
			if (i == index)
				scanf("%lf", &mid);
			else if (i == index + 1) {
				scanf("%lf", &temp);
				mid += temp;
				mid /= 2.0;
			}
			else
				scanf("%lf", &temp);
		}
	}
	if (n == 1) {
		printf("%d %d %d\n", l, l, l);
		return 0;
	}
	scanf("%d", &r);
	if (n == 2) {
		mid = (l + r);
	}
	if (r > l) {
		int t;
		t = l;
		l = r;
		r = t;
	}
	double tt = mid - (int)mid;
	if (tt==0.0) {
		printf("%d %.0lf %d\n", l, mid, r);
	}
	else
		printf("%d %.1lf %d\n", l, mid, r);
	return 0;
}