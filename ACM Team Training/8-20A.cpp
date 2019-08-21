#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
char ch[105];
int main(void) {
	cin >> ch;
	ll ans = 0;
	ll len = strlen(ch);
	if (len > 1)
		ans++;
	ans += (len - 1) / 2;
	bool flag = true;
	for (int i = len - 1; i > 0; i--)
	{
		if (ch[i] == '1') {
			flag = false;
			break;
		}
	}
	if (flag&&len > 2 && len & 1)
		ans--;
	if (ans == -1)
		ans = 0;
	printf("%lld\n", ans);
	return 0;
}