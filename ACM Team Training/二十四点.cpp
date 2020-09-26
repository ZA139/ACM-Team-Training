#include<string>
#include<iostream>
#include<cstring>
using namespace std;
string s;
bool map[8];
int main(void) {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		memset(map, 0, sizeof(map));
		cin >> s;
		long long sum= 0;
		for (int i = 1; i <7; i+=2)
		{
			if (s[i] == 'x') {
				s[i - 1] =s[i+1]= (s[i - 1] - '0') * (s[i + 1] - '0')+'0';
				s[i] = s[i + 1] = 'a';
			}
			else if (s[i] == '/') {
				s[i - 1] =s[i+1]= (s[i - 1] - '0')/(s[i + 1] - '0')+'0';
				s[i] = s[i + 1] = 'a';
			}
		}
		sum += s[0] - '0';
		for (int i = 1; i < 7; i += 2)
		{
			if (s[i] == '+') {
				sum+= (s[i + 1] - '0');
			}
			if (s[i] == '-') {
				sum -=(s[i + 1] - '0');
			}
		}
		if (sum == 24) {
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}