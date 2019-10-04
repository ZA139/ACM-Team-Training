//#include<cstdio>
//struct MyStruct
//{
//	bool on;
//	int begin;
//	int time;
//}lamp[105];
//int main(void) {
//	int n,nmsl;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%1d", &nmsl);
//		lamp[i].on = nmsl;
//	}
//	for (int i = 0; i <n; i++)
//	{
//		scanf("%d%d", &lamp[i].begin, &lamp[i].time);
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < n; j++) {
//			if ((i % lamp[j].begin==lamp[j].time)) {
//				lamp[j].on = !lamp[j].on;
//			}
//		}
//	}
//	return 0;
//}
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//struct MyStruct
//{
//	bool on;
//	int begin;
//	int time;
//}lamp[105];
//int ans[110];
//int an = 0;
//int main(void) {
//	memset(ans, 0, sizeof(ans));
//	int n, nmsl;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%1d", &nmsl);
//		lamp[i].on = nmsl;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d%d", &lamp[i].begin, &lamp[i].time);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (!lamp[i].on) {
//			for (int k = 1; k*lamp[i].begin < 100; k += 2)
//			{
//				for (int j = lamp[i].time + k * lamp[i].begin; j <lamp[i].time + k * lamp[i].begin + lamp[i].begin; j++) {
//					ans[j]++;
//				}
//			}
//		}
//		else {//on
//			for (int k = 1; k*lamp[i].begin <100; k+=2)
//			{
//				for (int j = lamp[i].time+k*lamp[i].begin; j <lamp[i].time + k * lamp[i].begin+lamp[i].begin; j++) {
//					ans[j]++;
//				}
//			}
//		}
//	}
//	for (int i = 0; i <=n; i++)
//	{
//		for (int j =0; j <=lamp[i].time; j++) {
//			ans[j] += (int)lamp[i].on;
//		}
//	}
//	for (int i = 1; i <100; i++)
//	{
//		an = max(an, ans[i]);
//	}
//	printf("%d\n", an);
//	return 0;
//}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans[110];
int ty[105];
int tt[105][2];
int main(void) {
	memset(ans, 0, sizeof(ans));
	int t = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%1d", &ty[i]);
	}
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &tt[i][0], &tt[i][1]);
	}
	for (int i = 0; i < t; i++)
	{
		if (ty[i]) {
			for (int j = 0; j < tt[i][1]; j++)
			{
				ans[j]++;
			}
			int temp = tt[i][0]+tt[i][1];
			while (temp<100)
			{
				for (int k = 0; k < tt[i][0]; k++)
				{
					ans[temp + k]++;
				}
				temp +=2*tt[i][0];
			}
		}
		else {
			int temp =tt[i][1];
			while (temp < 100)
			{
				for (int k = 0; k < tt[i][0]; k++)
				{
					ans[temp + k]++;
				}
				temp +=2*tt[i][0];
			}
		}
	}
	int ma = 0;
	for (int i = 0; i < 100; i++)
	{
		ma = max(ma, ans[i]);
	}
	printf("%d\n", ma);
	return 0;
}