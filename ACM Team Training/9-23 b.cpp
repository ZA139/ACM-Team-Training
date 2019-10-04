#include<iostream>
#include<string>
using namespace std;
string s;
int main(void) {
	ios::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	cin >> s;
	if (b) {
		if (a == 1) {
			s[0] = '0';
			b--;
		}
		else if (s[0] != '1') {
			s[0] = '1';
			b--;
		}
		for (int i = 1; i < a; i++)
		{
			if (!b)
				break;
			if (s[i] != '0') {
				s[i] = '0';
				b--;
			}
		}
	}
	cout << s << endl;
	return 0;
}