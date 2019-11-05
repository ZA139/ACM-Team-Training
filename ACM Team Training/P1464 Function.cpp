#include<cstdio>
#include<cstring>
long long ans[25][25][25];
typedef long long ll;
ll w(ll a, ll b, ll c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (ans[a][b][c] != 0) return ans[a][b][c];
	else if (a > 20 || b > 20 || c > 20) ans[a][b][c] = w(20, 20, 20);
	else if (a < b&&b < c) ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return ans[a][b][c];
}
int main(void) {
	long long a, b, c;
	while (scanf("%lld%lld%lld",&a,&b,&c)==3)
	{
		if (a == -1 && b == -1 && c == -1)
			break;
		//memset(ans, 0, sizeof(ans));
		printf("w(%lld, %lld, %lld) = ", a, b, c);
		if (a > 20) a = 21;
		if (b > 20) b = 21;
		if (c > 20) c = 21;
		printf("%lld\n", w(a, b, c));
	}
	return 0;
}