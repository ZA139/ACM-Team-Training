#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string s1, s2;
-int main(void) {
	ios::sync_with_stdio(false);
	while (cin >> s1 >> s2) {
		bool ans = true;
		int len = s1.size();
		int len2 = s2.size();
		int cnt = 0;
		for (int i = 0; i < len2; i++)
		{
			if (s1[cnt] == s2[i])
				cnt++;
			if (cnt == len)
				break;
		}
		if (cnt < len)
			ans = false;
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}