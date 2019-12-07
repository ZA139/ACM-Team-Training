//#include<cstdio>
//#include<algorithm>
//using namespace std;
//long long mates[500005];
//int len, n;
//
//bool check(long long x) {
//	long long l = 0, cnt = 0, r = 0;
//	for (int i = 0; i <n; ) {
//		if (cnt == 0) {
//			cnt++;
//			l = mates[i];
//			i++;
//		}
//		else {
//			r = mates[i];
//			cnt++;
//			if (r - l > x) {
//				if (cnt-1 < len) {
//					return false;
//				}
//				else {
//					cnt = 0;
//					r = 0;
//					l = 0;
//					continue;
//				}
//			}
//			i++;
//		}
//	}
//	return true;
//}
//
//int main(void) {
//	scanf("%d%d", &n, &len);
//	for (int i =0; i <n; i++) {
//		scanf("%lld", &mates[i]);
//	}
//	sort(mates, mates + n);
//	long long left = 0, right = 0x3f3f3f3f3f3f;
//	while (left <= right) {
//		long long mid = (left + right) >> 1;
//		if (check(mid)) {
//			right = mid - 1;
//		}
//		else {
//			left = mid + 1;
//		}
//	}
//	printf("%lld\n", left);
//	return 0;
//}

#include<cstdio>

#include<iostream>

#include<algorithm>

#include<queue>

#include<map>

#include<vector>

#include<set>

#include<string>

#include<cmath>

#include<cstring>

#define ll long long

#define pb push_back

#define pm make_pair

using namespace std;

const int MAX = 6e5 + 5;

int n, m;

int a[MAX], dp[MAX];

bool ok(int x) {

	// dp[0~m-1]=0

	for (int i = m; i <= n; i++) {

		if (a[i] - a[dp[i - m] + 1] <= x) dp[i] = i;

		else dp[i] = dp[i - 1];

	}

	return dp[n] == n;

}

int main()

{

	cin >> n >> m;

	for (int i = 1; i <= n; i++) scanf("%d", a + i);

	sort(a + 1, a + n + 1);

	int l = 0, r = 1e9;

	int mid = (l + r) >> 1;

	while (l < r) {

		mid = (l + r) >> 1;

		if (ok(mid)) r = mid;

		else l = mid + 1;

	}

	printf("%d\n", l);

	return 0;

}
