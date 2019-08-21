#include <cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 200005
int Tree[maxn << 2];
int Seq[maxn], Pos[maxn], Val[maxn];
int id;
void build(int rt, int l, int r) {
	Tree[rt] =r-l+1;
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}
void update(int rt, int p, int l, int r) {
	Tree[rt]--;
	int mid = l + r >> 1;
	if (l == r) {
		id = l;
		return;
	}
	if (Tree[rt << 1] >= p) {
		update(rt << 1, p, l, mid);
	}
	else{
		p -= Tree[rt << 1]; 
		update(rt << 1 | 1, p, mid + 1, r);
	}
}
int main() {
	int n, i;
	while (~scanf("%d", &n))
	{
		build(1,1,n);
		for (i = 1; i <= n; i++)
			scanf("%d%d", &Pos[i], &Val[i]);
		for (i = n; i >= 1; i--)
		{
			update(1,Pos[i]+1,1,n);
			Seq[id] = Val[i];
		}
		for (int i = 1; i <n; i++)
		{
			printf("%d ", Seq[i]);
		}
		printf("%d\n", Seq[n]);
	}
	return 0;
}