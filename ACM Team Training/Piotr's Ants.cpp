#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 5;
struct Ant
{
	int id;
	int p;
	int d;
}before[maxn],after[maxn];
bool cmp(Ant a, Ant b) {
	return a.p < b.p;
}
char dir[][10] = { "L","Turning","R" };
int order[maxn];
int main() {
	//freopen("txt.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int c=1;c<=t;c++)
	{
		printf("Case #%d:\n", c);
		int L, T, n;
		scanf("%d%d%d", &L, &T, &n);
		char ch;
		for (int i = 0; i < n; i++) {
			int loc;
			char ch=0;
			scanf("%d %c", &loc, &ch);
			int dir = ch == 'L' ? -1 : 1;
			before[i] = { i,loc,dir };
			after[i] = { 0,loc + T * dir,dir };
		}

		sort(before, before+n, cmp);
		for (int i = 0; i < n; i++) {
			order[before[i].id] = i;
		}

		sort(after, after + n, cmp);
		for (int i = 0; i <n; i++)
		{
			if (after[i].p == after[i + 1].p) {
				after[i].d = after[i + 1].d = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			int a = order[i];
			if (after[a].p<0 || after[a].p>L)
				printf("Fell off\n");
			else
				printf("%d %s\n", after[a].p, dir[after[a].d + 1]);
		}
		printf("\n");
	}
	return 0;
}