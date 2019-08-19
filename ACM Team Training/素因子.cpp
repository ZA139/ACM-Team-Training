#include<iostream>
#include<cstring>
#define MAXN 20010
using namespace std;
bool isprime[MAXN];
int ans, max = 0;
inline void prime() {
	int n = sqrt(MAXN + 0.5);
	memset(isprime, 0, sizeof(isprime));
	for (int i = 2; i <= n; i++)
	{
		if (!isprime[i])
		{
			for (int j = i * i; j <= MAXN; j += i)
				isprime[j] = true;
		}
	}
	return;
}
void slove(int a) {
	for (int i = a; i> 0; i--)
	{
		if (!isprime[i])
		{
			if (a%i==0&&max<i)
			{
				max = i;
				ans = a;
			}
		}
	}
}
int main(void) {
	int t;
	prime();
	isprime[1] = 0;
	while (~scanf("%d", &t)) {
		while (t--)
		{
			int b;
			scanf("%d", &b);
			slove(b);
		}
		printf("%d\n", ans);
		ans = 0;
		max = 0;
	}
	return 0;
}