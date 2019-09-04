//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main(void) {
//	long long tar, n, c,ans=0,l=0,r,t,temp1;
//	a
//	ans += c * n;
//	t = n;
//	while (n--)
//	{
//		temp1 = l;
//		if (tar == 1) {
//			break;
//		}
//		if (tar & 1) {
//			l = tar / 2;
//			r = l + 1;
//		}
//		else {
//			l = r = tar / 2;
//		}
//		ans += l * r;
//		tar = max(temp1,r);
//	}
//	int temp = 0;
//	printf("%lld\n", ans);
//	return 0;
//}
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void) {
	long long tar, n, c, ans = 0, normal, special, special_cnt, cnt, mid=0, mid_cnt = 0,remin=0;
	scanf("%lld%lld%lld", &tar, &n, &c);
	ans += c * n;
	long long num = n + 1;
	normal = tar / num;
	special = normal + 1;
	special_cnt = tar % num;
	cnt = num - special_cnt;
	ans += (normal*normal)*(cnt / 2);
	if (cnt & 1) {
		if (special_cnt != 0) {
			mid = normal + special;
			ans += normal * special;
			cnt--;
			special_cnt--;
		}
		else if (mid != 0)
		{
			mid = normal + mid;
			ans += normal * mid;
			cnt--;
		}
		else {
			remin = normal;
			cnt--;
		}
	}
	ans += special * special*(special_cnt / 2);
	if (special_cnt & 1)
		remin = special;
	normal = normal * 2;
	special = special * 2;
	cnt /= 2;
	special_cnt /= 2;
	while (cnt+special_cnt+(bool)remin+bool(mid)>1)
	{
		if (remin) {
			ans += normal * remin;
			remin = 0;
			cnt--;
		}
		ans += (normal*normal)*(cnt / 2);
		if (cnt & 1) {
			if (mid != 0) {
				mid = normal + mid;
				ans += normal * mid;
			}
			else {
				mid = normal + special;
				ans += normal * special;
				special_cnt--;
			}
			cnt--;
		}
		ans += special * special*(special_cnt / 2);
		if (special_cnt & 1)
			remin = special;
		cnt /= 2;
		special_cnt /= 2;
		normal = normal * 2;
		special = special * 2;
	}
	printf("%lld\n",ans);
	return 0;
}