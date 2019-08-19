#include<iostream>
#include<cstdio>
using namespace std;
int main(void) {
	long long a, b,ans;
	scanf("%lld", &a);
	while (a--)
	{
		ans = 0;
		scanf("%lld", &b);
		while (b)
		{
			if (b % 2 == 0)
			{
				b /= 2;
			}
			else
			{
				b--;
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}