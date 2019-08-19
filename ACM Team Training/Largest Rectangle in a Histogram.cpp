//#include<cstdio>
//#include<stack>
//#include<cstring>
//using namespace std;
//stack<long long>s;
//long long n, k[100010],ans=0;
//inline long long max(long long a, long long b)
//{
//	return a > b ? a : b;
//}
//inline void slove() {
//
//	for (long long i = 0; i < n+1; i++)
//	{
//		if (s.empty() || k[i] >= s.top())
//			s.push(k[i]);
//		else
//		{
//			long long cnt = 0;
//			while (!s.empty() && s.top() > k[i])
//			{
//				cnt++;
//				ans = max(ans, s.top()*cnt);
//				s.pop();
//			}
//			while (cnt--)
//			{
//				s.push(k[i]);
//			}
//			s.push(k[i]);
//		}
//	}
//}
//int main(void) {
//	while (1)
//	{
//		memset(k, 0, sizeof(k));
//		scanf("%lld", &n);
//		if (!n)
//			break;
//		for (long long i = 0; i < n; i++)
//		{
//			scanf("%lld", &k[i]);
//		}
//		k[n] = 0;
//		slove();
//		printf("%lld\n", ans);
//		ans = 0;
//	}
//	return 0;
//}
//#include<cstdio>
//#include<stack>
//#include<cstring>
//using namespace std;
//stack<long long>s;
//long long n, k[100010], ans = 0;
//inline long long max(long long a, long long b)
//{
//	return a > b ? a : b;
//}
//inline void slove() {
//
//	for (long long i = 0; i < n + 1; i++)
//	{
//		if (s.empty() || k[i] >= s.top())
//			s.push(k[i]);
//		else
//		{
//			long long cnt = 0;
//			while (!s.empty() && s.top() > k[i])
//			{
//				cnt++;
//				ans = max(ans, s.top()*cnt);
//				s.pop();
//			}
//			while (cnt--)
//			{
//				s.push(k[i]);
//			}
//			s.push(k[i]);
//		}
//	}
//}
//int main(void) {
//	for (scanf("%lld", &n);n; scanf("%lld", &n))
//	{
//		
//			memset(k, 0, sizeof(k));
//			for (long long i = 0; i < n; i++)
//			{
//				scanf("%lld", &k[i]);
//			}
//			k[n] = 0;
//			slove();
//			printf("%lld\n", ans);
//			ans = 0;
//		
//	}
//	return 0;
//}
#include<cstdio>
#include<cstring>
using namespace std;
int stack[100010], height[100010];
int main(void) {
	long long n,ans,top,a,l,r,i;
	for (scanf("%lld",&n);n ;scanf("%lld",&n))
	{
		memset(height, 0, sizeof(height));
		memset(stack, 0, sizeof(stack));
		height[0] = -1;//f
		ans = 0;
		top = 0;
		for ( i = 1; i <=n; i++)
		{
			scanf("%lld", &a);
			while( height[top] >= a)
			{
				l = i - 1 - stack[top - 1];
				r = height[top];
				ans = ans < (l*r)?( l * r) : ans;
				top--;
			}
			top++;
			height[top] = a;
			stack[top] = i;
		}
		a = 0;
		while (height[top]>=a)
		{
			l = i - 1 - stack[top - 1];
			r = height[top];
			ans = ans < (l*r) ? (l * r) : ans;
			top--;
		}
		printf("%lld\n", ans);
		}
	return 0;
}