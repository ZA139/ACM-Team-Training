#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string s, s1;
void slove(int a) {
	for (int i = a-1; i >=0; i--)
	{
		if (isalpha(s[i] + 1)) {
			s[i] += 1;
			return;
		}
		else
			s[i] = 'a';
	}
}
int main(void) {
	cin >> s;
	cin >> s1;
	if (s >= s1) {
		cout << "No such string\n";
		return 0;
	}
	else {
		slove(s.length());
		if (s< s1)
			cout << s << endl;
		else
			cout << "No such string\n";
		return 0;
	}
}