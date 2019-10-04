#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
long long staints[100010];
long long n, mad;
using namespace std;
bool check(long long a) {
	long long ans = 1;
	long long location = staints[0];
	for (long long i = 1; i < n; i++)
	{
		if (staints[i] -location  >= a)
		{
			ans++;
			location = staints[i];
		}
	}
	return ans >= mad;
}
int main(void) {
	memset(staints, 0, sizeof(staints));
	
	scanf("%intd%intd", &n, &mad);
	for (long long i = 0; i < n; i++)
	{
		scanf("%intd", &staints[i]);
	}
	sort(staints, staints + n);
	long long l = staints[0], r = staints[n - 1];
	while (l<=r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%intd\n", r);
	return 0;
}