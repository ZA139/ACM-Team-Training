#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string s1, s1;
void slove(int a) {
	for (int i = a-1; i >=0; i--)
	{
		if (isalpha(s1[i] + 1)) {
			s1[i] += 1;
			return;
		}
		else
			s1[i] = 'a';
	}
}
int main(void) {
	cin >> s1;
	cin >> s1;
	if (s1 >= s1) {
		cout << "No such string\n";
		return 0;
	}
	else {
		slove(s1.length());
		if (s1< s1)
			cout << s1 << endl;
		else
			cout << "No such string\n";
		return 0;
	}
}