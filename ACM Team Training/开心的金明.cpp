#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
long long w[26],v[26];
long long f[30005];
int main(void) {
	long long n, m,temp;
	scanf("%lld%lld", &n, &m);
	for (long long i = 0; i < m; i++)
	{
		scanf("%lld%lld", &w[i],&v[i]);
		v[i] *= w[i];
	}
	for (long long i = 0; i <m; i++)
	{
		for (long long j = n; j >= w[i]; j--)
			if(j>=w[i])
				f[j] = std::max(f[j], f[j - w[i]] + v[i]);
	}
	printf("%lld\n", f[n]);
	return 0;
}