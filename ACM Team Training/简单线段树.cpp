#include<cstdio>
#include<iostream>
using namespace std;
#define left(x) x*2
#define right(x) x*2+1
struct ass {
	int l, r;
	long long sum, add;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define add(x) tree[x].add
#define sum(x) tree[x].sum
}tree[100010*4];
int a[100010], n, m;

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	if (l == r)
	{
		sum(p) = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(left(p), l, mid);
	build(right(p), mid + 1, r);
	sum(p) = sum(left(p)) + sum(right(p));
}

void spread(int p) {
	if (add(p)) {
		sum(left(p)) += add(p)*(r(left(p)) - l(left(p)) + 1);
		sum(right(p)) += add(p)*(r(right(p)) - l(right(p)) + 1);
		add(left(p)) += add(p);
		add(right(p)) += add(p);
		add(p) = 0;
	}
}

void change(int p, int l,int r, int d) {
	if (l <= l(p) && r >= r(p)) {
		sum(p) += (long long)d*(r(p) - l(p) + 1);
		add(p) += d;
		return;
	}
	//spread(p);
	int mid = (l(p) + r(p)) >> 1;
	if (l <= mid)change(left(p), l, r, d);
	if (r > mid) change(right(p), l, r, d);
	sum(p) = sum(left(p)) + sum(right(p));
}

long long ask(int p, int l, int r) {
	if (l <= l(p) && r >= r(p)) return sum(p);
	spread(p);
	int mid = (l(p) + r(p)) >> 1;
	long long val = 0;
	if (l <= mid) val += ask(left(p), l, r);
	if (r > mid) val += ask(right(p), l, r);
	return val;
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	while (m--)
	{
		char op[2];
		int l, r, d;
		scanf("%s%d%d", op, &l, &r);
		if (op[0] == 'C') {
			scanf("%d", &d);
			change(1, l, r, d);
		}
		else
			printf("%lld\n", ask(1, l, r));
	}
	return 0;
}