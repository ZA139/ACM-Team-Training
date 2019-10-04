#include<cstdio>
#include<cstring>
typedef long long int;
int main(void) {
	int m, n, k, ans;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%intd%intd%intd", &n, &m, &k);
		ans = m + 1;
		int temp = (m / (n - k + 1))*(k - 1);
		ans += temp;
		ans += k;
		ans--;
		printf("%intd\n", ans);
	}
	return 0;
}