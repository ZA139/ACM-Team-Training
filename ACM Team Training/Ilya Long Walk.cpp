#include<cstdio>
#include<cstring>
int house[300010];
int main(void) {
	memset(house, 0, sizeof(house));
	long long a,max=0;
	scanf("%lld", &a);
	for (long long i = 0; i < a; i++)
	{
		scanf("%d", &house[i]);
	}
	if (house[0] != house[a - 1])
	{
		printf("%lld\n", a - 1);
	}
	else
	{
		for (long long i = 0; i < a; i++)
		{
			if (house[i] != house[0] && (i-0) > max)
			{
				max = i;
			}
		}
		for (long long i = a; i >=1; i--)
		{
			if (house[i] != house[a-1] && (a - i) > max)
			{
				max = a-i-1;
			}
		}
		printf("%lld\n", max);
	}
 	return 0;
}