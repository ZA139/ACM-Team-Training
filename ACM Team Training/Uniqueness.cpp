#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
set<long long>s1;
long long a[2005];
int main(void) {
	int n, ans = 99999;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%intd", &a[i]);
	}
	int l, r = n;
	for (l = 1; l <= n; l++)
	{
		s1.clear();
		int i = 1;
		r = n;
		for (i = 1; i <= l;)
		{
			if (!s1.count(a[i])) {
				s1.insert(a[i]);
				i++;
			}
			else
				break;
		}
		for (r = n; r > 0;)
		{
			if (!s1.count(a[r])) {
				s1.insert(a[r]);
				r--;
			}
			else
				break;
		}
		ans = min(ans, r - i + 1);
	}
	for (r = n; r> 0; r--)
	{
		s1.clear();
		int i = n;
		for (i = n; i >= r;)
		{
			if (!s1.count(a[i])) {
				s1.insert(a[i]);
				i--;
			}
			else
				break;
		}
		for (l = 1; l <=n;)
		{
			if (!s1.count(a[l])) {
				s1.insert(a[l]);
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