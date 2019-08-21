#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string s;
struct ass {
	int l, r, num, lan;
}camps[100005 << 2];
int a[100005];
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
void clear(int rt, int p) {
	if (camps[rt].l == camps[rt].r) {
		printf("%d\n", camps[rt].num);
		camps[rt].num = 0;
		return;
	}
	int mid = camps[rt].l + camps[rt].r >> 1;
	if (p <= mid)clear(rt << 1, p);
	else clear(rt << 1 | 1, p);

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
	int cnt = 1;
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int c = 0; c < T; c++)
	{
		memset(camps, 0, sizeof(camps));
		memset(a, 0, sizeof(a));
		int t,x;
		scanf("%d%d", &t,&x);
		for (int i = 1; i <= t; i++)
		{
			scanf("%d", &a[i]);
		}
		build(1, 1, t);
		printf("Case %d:\n", cnt++);
		while (x--)
		{
			int order, i, j;
			scanf("%d%d", &order, &i);
			if (order == 1) {
				clear(1, i+1);
			}
			else
			{
				scanf("%d", &j);
				if (order == 2) {
					add(1, i+1, j);
				}
				else if (order == 3) {
					printf("%d\n",que(1, i+1, j+1));
				}
			}
		}
	}
	return 0;
}
