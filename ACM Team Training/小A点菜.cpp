#include<cstdio>
#include<algorithm>
int ans=0, tmp[1005],f[1005];
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <=n; i++)
	{
		scanf("%d", &tmp[i]);
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= tmp[i]; j--)
			f[j] = f[j] + f[j - tmp[i]];
	printf("%d\n", f[m]);
	return 0;
}