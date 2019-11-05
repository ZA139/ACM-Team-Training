#include<cstdio>
#include<cstring>
bool dir[5005];
int f[5005];
int t;
char ch;
int slove(int K) {
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0;
	for (int i = 0; i+K <=t; i++)
	{
		if ((dir[i] + sum) % 2 != 0) {
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - K + 1 >= 0) {
			sum -= f[i - K + 1];
		}
	}
	for (int i =t-K+1; i < t; i++)
	{
		if ((dir[i] + sum) % 2 != 0) {
			return -1;
		}
		if (i - K + 1 >= 0) {
			sum -= f[i - K + 1];
		}
	}
	return res;
}
int main(void) {
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; i++) {
		ch = getchar();
		getchar();
		dir[i] = ch == 'F' ? 0 : 1;
	}
	int ans = 999999999, k;
	for (int i = 1; i <= t; i++)
	{
		int kk = slove(i);
		if (kk < ans&&kk>=0) {
			ans = kk;
			k = i;
		}
	}
	printf("%d %d\n", k, ans);
	return 0;
}