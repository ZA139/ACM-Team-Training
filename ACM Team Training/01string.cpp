#include<cstdio>
#include<cstring>
int a[100010],b[100010];
int main(void) {
	long long t,ans=0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%intd", &t);
	long long l1 = 0, l0 = 0;
	for (long long i = 1; i <= t; i++)
	{
		scanf("%1d", &a[i]);
		if (a[i] == 0)
			l0++;
		else
			l1++;
		b[i] = l0 - l1;
	}
	for (long long i = 0; i <=t; i++)
	{
		for (long long j = i+1; j <= t; j++) {
			if (b[i] == b[j])
			{
				ans = (j - i) > ans ? (j - i) : ans;
			}
		}
	}
	printf("%intd\n", ans);
	return 0;
}