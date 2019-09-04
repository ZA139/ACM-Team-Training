	#include<cstdio>
	#include<cstring>
	char s[200005];
	bool vis[200005];
	int ans;
	int len;
	//void slove(int a) {
	//	int l = a, r = a + 1;
	//	while (s[l]!=s[r]&&l>=0&&r<len)
	//	{
	//		if (vis[l] || vis[r]) {
	//			if (vis[l])
	//				l--;
	//			if (vis[r])
	//				r++;
	//		}
	//		else {
	//			vis[l] = vis[r] = 1;
	//			ans -= 2;
	//			l--; r++;
	//		}
	//	}
	//}
	int main(void) {
		memset(s, 0, sizeof(s));
		scanf("%d",&len);
		ans = len;
		int c1 = 0, c0 = 0;
		scanf("%s", s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '1')
				c1++;
			if (s[i] == '0')
				c0++;
			/*if (s[i] != s[i + 1]&&!vis[i]&&!vis[i+1]) {
				slove(i);
			}*/
		}
		ans = c1 - c0;
		if (ans < 0)
			ans = -ans;
		printf("%d\n", ans);
		return 0;
	}