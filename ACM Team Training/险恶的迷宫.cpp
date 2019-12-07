#include<cstdio>
#include<cmath>
#define eps 1e-7
long long r,a,b;
bool cal(double x,double y) {
	double R = r;
	double dis = SqrtByNewton((a - x)*(a - x) + (b - y)*(b - y));
	return dis <= R;
}
double SqrtByNewton(double x)
{
	double val = x;//最终
	double last;//保存上一个计算的值
	do
	{
		last = val;
		val = (val + x / val) / 2;
	} while (abs(val - last) > eps);
	return val;
}
int main(void) {
	long long n,ans=0;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &r);
	while (n--)
	{
		double x, y;
		scanf("%lf%lf", &x, &y);
		if (cal(x,y)) {
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}