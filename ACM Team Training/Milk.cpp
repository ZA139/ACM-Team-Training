#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(void) {
	int T = 0;
	cin >> T;
	while (T--) {
		string s, ans;
		int  precost = 99999999, ans_v = 0;
		//ans.clear();
		int K;
		cin >> K;
		while (K--)
		{
			int cost, v, day;
			cin >> s >> cost >> v;
			if (v < 200) continue;
			day = v / 200;
			if (day > 5)day = 5;
			if (((cost / day) < precost)|| ((cost / day) == precost && v > ans_v))
			{
				ans = s;
				ans_v = v;
				precost = cost /day;
			}
		}
		cout << ans << endl;
	}
	return 0;
}