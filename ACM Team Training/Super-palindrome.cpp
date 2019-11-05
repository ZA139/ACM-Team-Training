//#include<cstdio>
//#include<string>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//string s,sub,an;
//int mi = 999999;
//int main(void) {
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		mi = 999999;
//		cin >> s;
//		int len = s.length();
//		for (int j = 0; j < len; j+=2) {
//			int cnt = 0;
//			sub = s.substr(j, 2);
//			for (int i = 0; i < len; i += 2) {
//				if (s[i] != sub[0])
//					cnt++;
//				if (s[i] != sub[1])
//					cnt++;
//			}
//			if (cnt < mi) {
//				mi = cnt;
//				an = sub;
//			}
//		}
//		int ans = 0;
//		for (int i = 0; i < len; i++)
//		{
//			if (i&1) {
//				if (s[i] != an[1])
//					ans++;
//			}
//			else {
//				if (s[i] != an[0])
//					ans++;
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}
//奇数回文解法
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int main(void) {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		int c1[30], c2[30];
		s.clear();
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		cin >> s;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (i & 1) {
				c2[s[i] - 'a']++;
			}
			else
				c1[s[i] - 'a']++;
		}
		int ma=0, maa=0;
		for (int i = 0; i < 30; i++) {
			ma = max(ma, c1[i]);
			maa = max(maa, c2[i]);
		}
		cout << len - ma - maa << endl;
	}
	return 0;
}