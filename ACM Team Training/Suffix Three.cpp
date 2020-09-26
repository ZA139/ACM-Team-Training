#include<cstdio>
#include<iostream>
#include<string>
#include<DirectXMath.h>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s[s.length() - 1] == 'o') {
			cout << "FILIPINO\n";
		}
		else if (s[s.length() - 1] == 'u') {
			cout << "JAPANESE\n";
		}
		else if (s[s.length() - 1] == 'a') {
			cout << "KOREAN\n";
		}
	}
	return 0;
}