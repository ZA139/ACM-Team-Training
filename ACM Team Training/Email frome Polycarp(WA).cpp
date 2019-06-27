#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char s[10000000], s2[10000000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin >> t;
	while (t--)
	{
		int k = 0, cnt = 0;
		bool ans = true;
		cin >> s >> s2;
		long long len1 = strlen(s), len2 = strlen(s2);
		for (long long i = 0; i < len1&&k < len2; i++)
		{
			bool a = false;
			if (s[i] != s2[k]||cnt>0)
			{
				ans = false;
				break;
			}
			cnt = 0;
			while (s[i + 1] == s[i])
			{
				a = true;
				i++;
				cnt++;
			}
			if (a)
			{
				i++;
				a = false;
			}
			if (s2[k] == s[i])
			{
				k++;
				//cnt--;
			}
			while (s[k+1]==s[k])
			{
				k++;
				a = true;
				cnt--;
			}

		}
		if (ans)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}