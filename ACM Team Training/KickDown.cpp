#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s1, s2,s3;
bool slove(int a) {
	int len = s1.length();
	int len2 = s2.length();
	for (int i = 0; i <len; i++)
	{
		if (a + i > len2) return true;
		int te = s1[i] + s2[a+i] - 2 * '0';
		if (te > 3)
			return false;
	}
	return true;
}
bool xslove(int a) {
	int len = s1.length();
	//int len2 = s2.length();
	for (int i = 0; i < len; i++)
	{
		if (a-i < 0) return true;
		int te = s1[len-i-1] + s2[a-i] - 2 * '0';
		if (te > 3)
			return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false);
	//freopen("txt.txt", "w", stdout);
	while (cin>>s1>>s2)
	{
		if (s1.length()> s2.length()) {
			s3 = s1;
			s1 = s2;
			s2 = s3;
		}
		int ans = s2.length();
		int len = s2.length();
		int i = 0;
		for ( i = 0; i < len; i++)
		{
			if (slove(i))
				break;
		}
		int len1 = s1.length();
		int temp = i + s1.length();
		for ( i =len1-1; i >=0; i--)
		{
			if (xslove(i))
				break;
		}
		temp = min(temp, (len + (len1 - i - 1)));
		if (temp > s2.length())
			ans = temp;
		printf("%d\n", ans);
	}
}