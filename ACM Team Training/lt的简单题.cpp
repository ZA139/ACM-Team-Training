#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
long long ans[100000];
int main(void) {
	long long n;
	long long aa = 0;
	scanf("%lld", &n);
	for (long long i = 1; i <= 2 * n; i++) {
		ans[i] = i * i;
	}
	for (long long i = 2; i <= n + 1; i++) {
		aa += (i - 1)*ans[i];
	}
	int cnt = n - 1;
	for (long long i = n + 2; i <= 2 * n; i++) {
		aa += (cnt--)*ans[i];
	}
	printf("%lld", aa);
	return 0;
}