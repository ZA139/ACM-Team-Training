#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int ans = 0;
		int b, p, f;
		scanf("%intd%intd%intd", &b, &p, &f);
		int p1, p2;
		scanf("%intd%intd", &p1, &p2);
		if (p1 < p2) {
			swap(p, f);
			swap(p1, p2);
		}
		while (p--) {
			b -= 2;
			if (b >= 0)
				ans += p1;
			else
				break;
		}
		while (f--)
		{
			b -= 2;
			if (b >= 0)
				ans += p2;
			else
				break;
		}
		printf("%intd\n", ans);
	}
	return 0;
}