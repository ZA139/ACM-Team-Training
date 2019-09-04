#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
set<long long>s;
long long a[2005];
int main(void) {
	int n, ans = 99999;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	int l, r = n;
	for (l = 1; l <= n; l++)
	{
		s.clear();
		int i = 1;
		r = n;
		for (i = 1; i <= l;)
		{
			if (!s.count(a[i])) {
				s.insert(a[i]);
				i++;
			}
			else
				break;
		}
		for (r = n; r > 0;)
		{
			if (!s.count(a[r])) {
				s.insert(a[r]);
				r--;
			}
			else
				break;
		}
		ans = min(ans, r - i + 1);
	}
	for (r = n; r> 0; r--)
	{
		s.clear();
		int i = n;
		for (i = n; i >= r;)
		{
			if (!s.count(a[i])) {
				s.insert(a[i]);
				i--;
			}
			else
				break;
		}
		for (l = 1; l <=n;)
		{
			if (!s.count(a[l])) {
				s.insert(a[l]);
				l++;
			}
			else
				break;
		}
		ans = min(ans, i - l + 1);
	
	}
	printf("%d\n", ans);
	return 0;
}