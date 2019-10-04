#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroint-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcainter-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroint-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-fointow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-smaint-functions")
#pragma GCC optimize("-finline-smaint-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-caints")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-cainted-once")
#pragma GCC optimize("-fdelete-nuint-pointer-checks")
#define INF 0x3f3f3f3f3f3f3f3f
#define PI acos(-1.0)
using namespace std;
const int Max = 5e4;
int N;
typedef struct Tree {
	int L, R;
	int sum = 0;
	int lazy;
	int Max;
}Tree;
Tree tree[Max << 2];
typedef long long int;
int a, b;
void push_up(int x)
{
	if (tree[x << 1].sum == a || tree[x << 1].sum == b)
		tree[x].sum += tree[x << 1].sum;
	if (tree[x << 1 | 1].sum == a || tree[x << 1 | 1].sum == b)
		tree[x].sum += tree[x << 1 | 1].sum;
	tree[x].Max = max(tree[x << 1].Max, tree[x << 1 | 1].Max);
}
void push_down(int x, int num)
{
	if (tree[x].lazy) {
		tree[x << 1].sum += tree[x].lazy*(num - (num / 2));//Ã¿¸öµãÐèÒª¸üÐÂµÄÖµ*¸öÊý
		tree[x << 1 | 1].sum += tree[x].lazy*(num / 2);
		tree[x << 1].Max = tree[x].Max + tree[x].lazy;
		tree[x << 1 | 1].Max = tree[x].Max + tree[x].lazy;
		tree[x << 1].lazy += tree[x].lazy;
		tree[x << 1 | 1].lazy += tree[x].lazy;
		tree[x].lazy = 0;
	}
}
void build(int x, int l, int r)
{
	tree[x].L = l;
	tree[x].R = r;
	tree[x].sum = 0;
	tree[x].lazy = 0;
	if (l == r) {
		tree[x].sum = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	push_up(x);
}
int main()
{
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	build(1, a, b);
	if (a == b)
		cout << 2 * a << endl;
	else
		cout << tree[1].sum << endl;
	return 0;
}
