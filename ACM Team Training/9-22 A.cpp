#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[105];
bool map[105];
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &num[i]);
		map[num[i]] = true;
	}
	long long ans =0;
	sort(num, num + t);
	for (int i = 0; i < t; i++)
	{
		if (map[num[i]]) {
			map[num[i]] = false;
			ans++;
		}
		for (int j = 2; j*num[i] <= 100; j++)
		{
			if (map[num[i] * j]) {
				map[num[i] * j] = false;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}