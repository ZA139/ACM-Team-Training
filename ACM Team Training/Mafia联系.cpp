#include<cstdio>
#include<algorithm>
using namespace std;
long long t;
long long gamers[100005];
bool check(long long x) {
	long long sum = 0;
	for (long long i = 0; i < t; i++) {
		sum += x - gamers[i];
	}
	return sum >=x;
}
int main(void) {
	long long ma = 0;
	scanf("%I64d", &t);
	for (long long i = 0; i < t; i++) {
		scanf("%I64d", &gamers[i]);
		ma = max(ma, gamers[i]);
	}
	long long left = ma, right = 99999999999999;
	while (left<=right)
	{
		long long mid = (left + right) >> 1;
		if (check(mid)) {
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	printf("%I64d\n", left);
	return 0;
}