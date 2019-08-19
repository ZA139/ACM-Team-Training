#include<cstdio>
#include<cstring>
using namespace std;
int main(void)
{
	int map[25],n,a;
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	map[0] = 1;
	map[1] = 3;
	for (int i =2; i < 21; i++)
	{
		map[i] = 2 * map[i - 1] + map[i - 2];
	}
	while (n--)
	{
		scanf("%d", &a);
		printf("%d\n", map[a]);
	}
	return 0;
}