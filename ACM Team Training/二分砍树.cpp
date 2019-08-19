#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n, m, ans, highest = 0, smallest = 99999999999999;
long long tree[1000010];
long long max(long long a, long long b) {
	return a > b ? a : b;
}
long long min(long long a, long long b) {
	return a > b ? b:a;
}
bool check(long long a) {
	ans = 0;
	for (long long i = 0; i < n; i++)
	{
		if (tree[i]>a)
		{
			ans += tree[i] - a;
		}
	}
	return ans >= m;
}

int main(void) {
	memset(tree, 0, sizeof(tree));
	scanf("%lld%lld", &n, &m);
	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &tree[i]);
		highest = max(highest, tree[i]);
		smallest = min(smallest, tree[i]);
	}
	while (smallest<=highest)
	{
		long long mid = (smallest + highest) >> 1;
		if (!check(mid))highest=mid-1;
		else smallest = mid + 1;
	}
	printf("%lld\n", highest);
	return 0;
}