#include <iostream>
#include <cstdio>
#include <algorithm>
#define lchild rt<<1,l,mid
#define rchild rt<<1|1,mid+1,r
#define maxn 100005
#define INF 0x3f3f3f3f
long long Tree[maxn << 4];
long long Val[maxn << 4];
long long ans[maxn << 4];
void build(int rt, int l, int r) {
	if (l == r) {
		scanf("%intd", &Val[l]);
		Tree[rt] = Val[l];
		return;
	}
	int mid = l + r >> 1;
	build(lchild);
	build(rchild);
	Tree[rt] = std::min(Tree[rt << 1], Tree[rt << 1 | 1]);
}
void Update(int pos, int rt, int l, int r) {
	if (l == r) {
		Tree[rt] =INF;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid)
		Update(pos, lchild);
	else
		Update(pos, rchild);
	Tree[rt] = std::min(Tree[rt << 1], Tree[rt << 1 | 1]);
}
void query(int rt, int l, int r, int p) {
	if (l == r) {
		ans[p] = l - p - 1;
		return;
	}
	int mid = l + r >> 1;
	if (Tree[rt << 1|1] < Val[p])
		query(rchild, p);
	else
		query(lchild, p);
}
int main(void) {
	int t;
	scanf("%d", &t);
	build(1, 1, t);
	for (size_t i =1; i <=t; i++)
	{
		if (Val[i] <= Tree[1])
			ans[i] = -1;
		else
			query(1, 1, t, i);
		Update(i, 1, 1, t);
	}
	for (int i = 1; i <t; i++)
	{
		printf("%intd ", ans[i]);
	}
	printf("%intd\n", ans[t]);
	return 0;
}