#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string s;
struct ass {
	int l, r, num, lan;
}camps[50005 << 2];
int a[50005];
void build(int rt, int l, int r) {
	camps[rt].l = l, camps[rt].r = r;
	if (l == r) {
		camps[rt].num = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);

	camps[rt].num = camps[rt << 1].num + camps[rt << 1 | 1].num;
}
void add(int rt, int p, int val) {
	if (camps[rt].l == camps[rt].r) {
		camps[rt].num += val;
		return;
	}
	int mid = camps[rt].l + camps[rt].r >> 1;
	if (p <= mid)add(rt << 1, p, val);
	else add(rt << 1 | 1, p, val);

	camps[rt].num = camps[rt << 1].num + camps[rt << 1 | 1].num;
}
int que(int rt, int l, int r) {
	if (camps[rt].l >= l && camps[rt].r <= r)
		return camps[rt].num;
	int mid = camps[rt].l + camps[rt].r >> 1;
	int ans = 0;
	if (l <= mid)ans += que(rt << 1, l, r);
	if (r > mid)ans += que(rt << 1 | 1, l, r);
	return ans;
}
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int c = 0; c < T; c++)
	{
		memset(camps, 0, sizeof(camps));
		memset(a, 0, sizeof(a));
		int t;
		scanf("%d", &t);
		for (int i = 1; i <= t; i++)
		{
			scanf("%d", &a[i]);
		}
		build(1, 1, t);
		printf("Case %d:\n", c + 1);
		int j, i;

		while (cin >> s && s[0] != 'E') {
			cin >> i >> j;
			if (s[0] == 'A') {
				add(1, i, j);
			}
			else if (s[0] == 'S')
				add(1, i, -j);
			else if (s[0] == 'Q')
				printf("%d\n", que(1, i, j));

		}
	}
	return 0;
}
