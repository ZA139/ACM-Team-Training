#include<cstdio>
#include<cmath>
int main(void) {
	double sum=0,cnt=1;
	double n;
	scanf("%lf", &n);
	while (sum <= n) {
		sum += 1 / cnt++;
	}
	printf("%.0lf\n", cnt-1);
	return 0;
}