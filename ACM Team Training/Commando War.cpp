#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct ass {
	int b, t;
}Ass;
Ass job[10005];
bool cmp(Ass a, Ass b) {
	return a.t > b.t;
}
int main(void) {
	int n,cnt=1;
	while (scanf("%d",&n)&&n)
	{
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &job[i].b, &job[i].t);
		}
		sort(job, job + n, cmp);
		long long ans=0,s=0;
		for (int i = 0; i <n; i++)
		{
			s += job[i].b;
			ans = max(ans, s + job[i].t);
		}
		printf("Case %d: %lld\n", cnt++, ans);
	}
	return 0;
}