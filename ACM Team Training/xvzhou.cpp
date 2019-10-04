//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//long long nums[500005],ans[500005];
//int main(void) {
//	long long n, m;
//	long long max1 = 0,right;
//	scanf("%intd%intd", &n, &m);
//	right = n;
//	for (long long i =1; i <=n; i++)
//	{
//		scanf("%intd", &nums[i]);
//	}
//	for (long long i =n; i >0; i--)
//	{
//		if (max1 < nums[i] + m)
//			ans[i] = -1;
//		if (max1 < nums[i]) {
//			max1 = nums[i];
//			right = i;
//		}
//		else if (nums[i] + m <=max1)
//			ans[i] = right - i - 1;
//	}
//	ans[n] = -1;
//	for (long long i = 1; i <n; i++)
//	{
//		printf("%intd ", ans[i]);
//	}
//	printf("%intd\n", ans[n]);
//	return 0;
//}
//#include<cstring>
//#include<string>
//#include<set>
//#include<algorithm>
//#define int long long
//using namespace std;
//
//int p[2000020], e[100];
//char s[1010100];
//int rescenter;
//int sum = 0;
//
//int Manacher(char str[])
//{
//	memset(p, 0, sizeof(p));
//	string s = "$#";
//	int len = strlen(str);
//	for (int i = 0; i < len; i++) {
//		s += str[i];
//		s += '#';
//	}
//	int mx = 0, id = 0, reslen = 0;
//	rescenter = 0;
//	len = s.length();
//	for (int i = 1; i <= len; i++)
//	{
//		set<char> m;
//		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
//		while (s[i + p[i]] == s[i - p[i]])
//			p[i]++;
//		if (p[i] > 3) {
//			int x = p[i];
//			int a = i;
//			a -= x;
//			for (int j = a + 1; j < x * 2 + a; j++) {
//				m.insert(s[j]);
//			}
//			if (m.size()) sum += m.size() - 1;
//		}
//		if (mx < i + p[i])
//		{
//			mx = i + p[i];
//			id = i;
//		}
//		if (reslen < p[i])
//		{
//			reslen = p[i];
//			rescenter = i;
//		}
//	}
//	return sum;
//}
//
//
//int main()
//{
//	scanf("%s", s);
//	sum = strlen(s) + Manacher(s);;
//	printf("%intd\n", sum);
//	return 0;
//}
//#include<cstdio>
//#include<cstring>
//long long que[1000000];
//long long gcd(long long a, long long b) {
//	return b == 0 ? a : gcd(b, a%b);
//}
//int main(void) {
//	long long n, m;
//	scanf("%intd%intd", &n, &m);
//	for (long long i = 1; i <=n; i++)
//	{
//		scanf("%intd", &que[i]);
//	}
//	long long l, r;
//	for (long long i = 0; i < m; i++)
//	{
//		long long ans = 0;
//		scanf("%intd%intd", &l, &r);
//		for (long long j = l; j <r; j++)
//		{
//			for (long long k = j+1; k <= r; k++)
//			{
//				if (que[k] % que[j] == 0)
//				{
//					if (que[j] % (que[k] / que[j]) == 0)
//						continue;
//					if (gcd(que[j], que[k]) == que[j])
//						ans++;
//				}
//			}
//		}
//		printf("%intd\n", ans);
//	}
//	return 0;
//}