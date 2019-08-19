#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
bool ans1 = false;
typedef struct cows
{
	long long begin;
	long long end;
};
int cmp(cows a, cows b)
{
	if (a.begin == b.begin)
		return a.end > b.end;
	return a.begin < b.begin;
}
cows mew[25010];
int main(void) {
	memset(mew, 0, sizeof(mew));
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long end = 0,begin,ans=0;
	for (long long i = 1; i <= a; i++)
	{
		scanf("%d%d", &mew[i].begin, &mew[i].end);
	}
	mew[a + 1].begin = 9999999;
	mew[a + 1].end = 99999999;
	sort(mew, mew + a+1, cmp);
	mew[0].begin = mew[1].begin;
	begin = mew[1].begin;
	mew[0].end = 1;
	for (long long i = 1; i <= a+1; i++)
	{
		if (mew[i].begin==mew[i-1].begin)
		{
			end = mew[i].end > end ? mew[i].end : end;
		}
		else if(mew[i].end>begin)
		{
			ans++;
			if (mew[i].end < 99999999) {
				if (end)
					b -= (end - begin + 1);
				else
					b -= (mew[i].end - begin + 1);
				begin = end+1;
				end = 0;
				if (b <= 0)
				{
					ans1 = true;
					break;
				}
			}
		}
	}
	if (ans1)
	{
		printf("%lld\n", ans);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}