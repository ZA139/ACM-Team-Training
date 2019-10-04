#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
char s[200005];
long long sum[200005];
using namespace std;
int main(void) {
	long long len, n, sum88 = 0;
	scanf("%lld%lld", &len, &n);
	getchar();
	for (long long i =1; i <=len; i++)
	{
		scanf("%1c", &s[i]);
		sum[i] = sum88;
		if (s[i] == '8')
			sum88++;
	}
	sum[len+1] = sum88;
	while (n--)
	{
		bool flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 0,flag5=1;
		long long l, r;
		scanf("%lld%lld", &l, &r);
		for (int i = r; i >= l; i--)
		{
			if (flag3) {
				if (s[i] == '2')
					flag3 = 0;
			}
			else if (flag2) {
				if (s[i] == '0')
					flag2 = 0;
			}
			else if (flag1) {
				if (s[i] == '1')
					flag1 = 0;
					r = i;
			}
			else if (flag5) {
				if (s[i] == '9') {
					flag5 = 0;
					flag4 = 1;
					break;
				}
			}
		}
			if (!flag4)
				printf("-1\n");
			else {
				printf("%lld\n", sum[r] - sum[l]);
			}
	}
	return 0;
}
//还有删1，0，2的情况