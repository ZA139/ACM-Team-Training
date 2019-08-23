#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll A, B, C;
int main(void) {
	ll t;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld", &A, &B);
		if (A&B) {
			printf("%lld\n", A&B);
		}
		else
			printf("1\n");
	}
	return 0;
}