#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string s, s2;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		cin >> s >> s2;
		int len1 = s.length();
		if (s<s2) {
			cout << s << endl;
			continue;
		}
		else {
			int r = 0;
			bool flag = false;
			for (int i = 0; i < len1 - 1; i++) {
				int l = i;
				for (int j = len1 - 1; j >= l+1; j--) {
					if (s[i] > s[j]) {
						i = j;
						r = j;
						flag = true;
					}
				}
				if (flag) {
					swap(s[l], s[r]);
					break;
				}
			}
			if (s < s2) {
				cout << s << endl;
			}
			else {
				cout << "---\n";
			}
		}
	}
	return 0;
}