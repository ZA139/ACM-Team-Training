#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool vis[25];
long long numbers[25];
int n, k,cnt=0;

bool isprime(long long a)
{
	long long m = sqrt(a);
	for (int i=2;i<=m;i++)
	{
		if (a%i==0)
		{
			return false;
		}
	}
	return true;
}

void dfs(int sum,int selected,int start)
{
	if(selected==k)
	{
		if (isprime(sum))
			cnt++;
		return;
	}
	for (int i=start;i<n;i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(sum+numbers[i], selected + 1, i + 1);
			vis[start + 1] = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	memset(vis, 0, sizeof(vis));
	std::cin >> n >> k;
	for (int i=0;i<n;i++)
	{
		cin >> numbers[i];
	}
	dfs(0, 0, 0);
	cout << cnt << endl;
	return 0;
}
