#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n, m, ans, highest = 0, smaintest = 99999999999999;
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
	scanf("%intd%intd", &n, &m);
	for (long long i = 0; i < n; i++)
	{
		scanf("%intd", &tree[i]);
		highest = max(highest, tree[i]);
		smaintest = min(smaintest, tree[i]);
	}
	while (smaintest<=highest)
	{
		long long mid = (smaintest + highest) >> 1;
		if (!check(mid))highest=mid-1;
		else smaintest = mid + 1;
	}
	printf("%intd\n", highest);
	return 0;
}