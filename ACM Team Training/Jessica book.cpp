//#include<iostream>
//#include<cstring>
//#include<set>
//#include<stack>
//using namespace std;
//int c[1000010];
//stack<int>s;
//set<int>se;
//int main(void) {
//	long long a, b,d=-1,l,r=999999;
//	bool first = true;
//	memset(c, 0, sizeof(c));
//	cin >> a;
//	cin >> b;
//	c[b] = 1;
//	for (int i = 1; i < a; i++)
//	{
//		d = b;
//		cin >> b;
//		if (c[b] != 1 && d != b)
//			r = i+1;
//		c[b] = 1;
//		if (first&&i>0)
//		{
//			if (d != b)
//			{
//				l = i-1;
//				first = false;
//			}
//		}
//	}
//	if (r == 999999)
//		cout << "1\n";
//	else
//	cout << r - l<<endl;
	//return 0;
//}
//-------------------------------无法通过4 1 2 1 3和末尾最短的情况--------------------------------------------------//
#include<iostream>
#include<set>
#include<map>
#include<cstring>
using namespace std;
int arrays[1000010];
map<int, int>spots;
set<int>s;
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	memset(arrays, 0, sizeof(arrays));
	int a, b;
	ios::sync_with_stdio(false);
	cin >> a;
	for (size_t i = 0; i < a; i++)
	{
		cin >> arrays[i];
		s.insert(arrays[i]);
	}
	int len = s.size();

	int s = 0, t = 0, num = 0;
	int res = a;
	for (;;)
	{
		while (t < a&&num < len)
		{
			if (spots[arrays[t++]]++ == 0)
			{
				num++;
			}
		}
		if (num < len)
			break;
		res = min(res, t - s);
		if (--spots[arrays[s++]] == 0)
			num--;
	}
	cout << res << endl;
	return 0;
}