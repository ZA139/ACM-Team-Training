#include<iostream>//极端复杂情况不可取
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double cake[10010];
const double pie = acos(-1.0);
const double eps = 1e-7;
long long t, N, F;
double ca(double r) {
	return (pie*r*r);
}
bool check(double r) {
	long long ans = 0;
	for (long long i = 0; i < N; i++)
	{
		ans += (cake[i] / r);
	}
	return ans >= F;
}
int main(void) {

	scanf("%lld", &t);
	while (t--)
	{
		memset(cake, 0, sizeof(cake));
		scanf("%lld%lld", &N, &F);
		F++;
		for (int i = 0; i < N; i++)
		{
			scanf("%lf", &cake[i]);
			cake[i] = ca(cake[i]);
		}
		sort(cake, cake + N);
		double l = 0;
		double r = cake[N - 1];
		while (l+eps<r)
		{
			double mid = (l + r) /2.0;
			if (!check(mid))
				r = mid;
			else
				l = mid;
		}
		printf("%.4lf\n", r);
	}
	return 0;
}