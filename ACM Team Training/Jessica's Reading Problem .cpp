#include<cstdio>
#include<set>
#include<map>
#include<cstring>
using namespace std;
int arrays[1000010];
map<int, int>spots;
set<int>s;
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	memset(arrays, 0, sizeof(arrays));
	int a, b;
	scanf("%d", &a);
	for (size_t i = 0; i < a; i++)
	{
		scanf("%d", &arrays[i]);
		s.insert(arrays[i]);
	}
	int len = s.size();

	int s = 0, t = 0, num = 0;
	int res = a;
	for (;;)
	{
		while (t < a&&num < len)
		{
			if (spots[arrays[t++]]++ == 0)
			{
				num++;
			}
		}
		if (num < len)
			break;
		res = min(res, t - s);
		if (--spots[arrays[s++]] == 0)
			num--;
	}
	printf("%d", res);
	return 0;
}