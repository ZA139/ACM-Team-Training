//#include<cstdio>
//#include<set>
//#include<cstring>
//using namespace std;
//long long ans = 0;
//set<long long> s;
//int t;
//long long stu[7005][2];
//long long temp[7005];
//void slove(long long a) {
//	int ck = 0;
//	long long cnt = 0;
//	int cntt = 0;
//	memset(temp, 0, sizeof(temp));
//	temp[cntt++] = a;
//	s.insert(a);
//	for (int i = 0; i < t; i++)
//	{
//		for (int j = 0; j <cntt; j++)
//		{
//			if (stu[i][0] <temp[j]&& a&stu[i][0] == stu[i][0])
//			{
//				
//				cnt += stu[i][1];
//			}
//		}
//
//		if (stu[i][0] == a) {
//			cnt += stu[i][1];
//			ck++;
//		}
//	}
//	if (ck > 1)
//		ans = ans > cnt ? ans : cnt;
//	return;
//}
//int main(void) {
//	s.clear();
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		scanf("%lld", &stu[i][0]);
//	}
//	for (int i = 0; i < t; i++)
//	{
//		scanf("%lld", &stu[i][1]);
//	}
//	for (int i = 0; i < t; i++)
//	{
//		if (!s.count(stu[i][0])) {
//			slove(stu[i][0]);
//		}
//	}
//	printf("%lld\n", ans);
//	return 0;
//}
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
ll n, a[7005], b[7005];
ll ans;
vector <int> V;
map <ll, int> cnt;
bool map[7005];
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i]] > 1) {
			V.push_back(i);
			map[i] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (map[i])
			continue;
		for (auto A : V) {
			if (a[A] > a[i] && ((a[A] & a[i]) == a[i])) {
				V.push_back(i);
				map[i] = true;
				break;
			}
		}
	}
	for (auto A : V)
		ans += b[A];
	printf("%lld\n", ans);
	return 0;
}