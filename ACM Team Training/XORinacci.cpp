#include<cstdio>
#include<cstring>
long long a[3];
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int o;
		scanf("%lld%lld%d", &a[0],&a[1],&o);
		o%= 3;
		if (o == 0)
			printf("%lld\n", a[0]);
		else if (o==2)
			printf("%lld\n", a[0] ^ a[1]);
		else
			printf("%lld\n", a[1]);
	}
	return 0;
}