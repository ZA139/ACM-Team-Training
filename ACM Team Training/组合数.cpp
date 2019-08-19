#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
int num[2000],visit[2000],buffer[2000];
using namespace std;
int main(void)
{
	int a,n,k;
	scanf("%d", &a);
	while (a--)
	{
		int cnt = 0;
		memset(num, 0, sizeof(num));
		memset(visit, 0, sizeof(visit));
		memset(visit, 0, sizeof(visit));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j) {
					long long temp = llabs(num[i] - num[j]);
					if (!visit[temp])
					{
						buffer[cnt++] = temp;
						visit[temp] = 1;
					}
				}
			}
		}
		sort(buffer, buffer + cnt);
		printf("%d\n", buffer[k-1]);
	}
	return 0;
}