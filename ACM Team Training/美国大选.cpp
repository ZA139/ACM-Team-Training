#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstring>
using namespace std;
long long states[1050];
int main(void) {
	int t;
	long long ans;
	while (scanf("%d",&t)&&t)
	{
		ans = 0;
		memset(states, 0, sizeof(states));
		for (int i = 0; i < t; i++)
		{
			scanf("%lld", &states[i]);
		}
		sort(states, states + t);
		if (t % 2 == 0)
		{
			for (int i = 0; i < (t/2)+1; i++)
			{
					ans += states[i] / 2;
					/*if (states[i] % 2 != 0)*/
						ans++;
			}
		}
		else
		{
			for (int i = 0; i <( t / 2)+1; i++)
			{
				ans += states[i] / 2;
				/*if (states[i] % 2 != 0)*/
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}