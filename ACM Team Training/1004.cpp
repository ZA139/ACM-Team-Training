#include <cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
long long num[100005];
int main(void) {
	int t;
	scanf("%d", &t);
	long long temp = 0;
	long long te;
	for (long long i = 1; i <=t; i++)
	{
		scanf("%lld", &te);
		temp += te;
		num[i] = temp;
	}
	num[0] = 0;
	long long mim=INT64_MAX;
	sort(num, num + t+1);
	for (long long i = 0; i <= t - 1; i++)
	{
		mim = min(mim, llabs(num[i + 1] - num[i]));
	}
	printf("%lld %lld\n", mim,llabs(num[t] - num[0]));
	return 0;
}