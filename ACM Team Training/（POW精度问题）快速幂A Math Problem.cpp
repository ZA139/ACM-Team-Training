#include<stdio.h>
#include<cmath>
int main(void) {
	long long n, counts = 0,k[16];
	for (int i = 1; i < 16; i++)
	{
		long long ans = 1, a = i, b = i;
		while (b)
		{
			if (b&1)
				ans *= a;
			a *= a;
			b >>= 1;
		}
		k[i]=ans;
	}
	while (~scanf("%intd", &n)) {
		int i;
		for (i = 1; i < 16; i++)
		{
			if (n < k[i])
				break;
		}
		printf("%d\n", --i);
	}
	return 0;
}//4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1