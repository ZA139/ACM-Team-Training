#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool vis[25];
long long numbers[25];
int n, k, cnt = 0;
#define MAXN 100000005
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

void dfs(int sum, int selected, int start)
{
	if (selected == k)
	{
		if (!isprime[sum])
			cnt++;
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(sum + numbers[i], selected + 1, i + 1);
			vis[start + 1] = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	memset(vis, 0, sizeof(vis));
	prime();
	isprime[1] = 1;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	dfs(0, 0, 0);
	cout << cnt << endl;
	return 0;
}