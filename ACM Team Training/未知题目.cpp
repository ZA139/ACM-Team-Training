//#include<iostream>
//using namespace std;
//int cnt = 1;
//void sln(int a) {
//	for (int i = 1; i <=a/2; i++)
//	{
//		//if (!judge[i])
//			cnt++;
//		sln(i);
//	}
//}
//int main(void) {
//	int a;
//	ios::sync_with_stdio(false);
//	cout.tie(0);
//	//freopen("txt.txt", "w", stdout);
//	cout << "{";
//	for (a = 1; a < 120; a++) {
//		cnt = 1;
//		sln(a);
//		cout << cnt <<",";
//	}
//	cout << "}";
//	return 0;
//}±©Á¦µÝ¹étle
#include<iostream>
#include<cstring>
using namespace std;
long long ans[1005];
int main(void) {
	int n;
	cin >> n;
	memset(ans, 0, sizeof(ans));
	ans[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		ans[i] = ans[i /2] + ans[i % 2 == 0 ? i - 1 : i - 2];
	}
	cout << ans[n] << endl;
	return 0;
}