#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	ll mi = a-b+1;
	ll mx = 1;
	ll len = b - 1;
	ll temp = 2;
	while (len--&&len>=0)
	{
		mi += temp;
		temp *= 2;
	}
	len = c - 1;
	temp = 1;
	while (len--&&len>=0)
	{
		temp *= 2;
		mx += temp;
	}
	len = a-c;
	while (len--&&len>=0)
	{
		mx += temp;
	}
	printf("%lld %lld\n", mi, mx);
	return 0;
}