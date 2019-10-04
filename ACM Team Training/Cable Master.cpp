#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-7
long long n, m;
double len[10005];
///<param>nmsl<param/>5
bool check(double length) {
	long long cnt = 0;
	for (long long i = 0; i < n; i++)
	{
		cnt +=(int)(len[i] / length);
	}
	return cnt >= m;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
	{
		cin >> len[i];
	}
	double l = 0.0, r = 10000000.0, mid;
	while (l + eps <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		}
		else
			r = mid;
	}
	printf("%.2f\n", floor(r * 100) / 100.0);
	return 0;
}	