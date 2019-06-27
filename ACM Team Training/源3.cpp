#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(void){
	int a, b, c;
	string s;
	cin >> a >> b >> c;
	cin >> s;
	int counts = 0,ans=0;
	for (int i = s.length()-1;counts<=b; i--,b++)
	{
		if (counts == c)
		{
			ans += s[i] != '1';
		}
		else
		{
			ans += s[i] == '1';
		}
	}
	printf("%d\n",ans);
	return 0;
}