#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
string s;
int len;
bool slove(int a) {
	string sub = s.substr(0, a);
	string temp;
	for (int i = a; i < len; i+=a)
	{
		temp = s.substr(i, a);
		if (sub != temp)
			return false;
	}
	return true;
}
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		s.clear();
		cin >> s;
		len = s.length();
		for (int i = 1; i <=len / 2; i++)
		{
			if (len%i == 0) {
				if (slove(i)) {
					printf("%d\n", i);
					goto x;
				}
			}
		}
		printf("%d\n", len);
	x:
		if (t != 0)
			printf("\n");
	}
	return 0;
}