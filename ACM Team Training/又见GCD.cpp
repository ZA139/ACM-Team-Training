#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	return b==0 ? a : gcd(b, a%b);
}
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		long long a, b;
		cin >> a >> b;
		for (long long i = 2 * b; i < 1000000; i=i+b)
		{
			if (gcd(a, i) == b)
			{
				printf("%lld\n", i);
				break;
			}
		}
	}
	return 0;
}