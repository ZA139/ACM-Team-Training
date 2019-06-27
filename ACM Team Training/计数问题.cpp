#include<stdio.h>
#include<string.h>
#include<iostream>
char buff[100000000];
using namespace std;
int main(void) {
	long long a, cnt = 0,b;
	cin >> a>>b;
	b += '0';
	memset(buff, 0, sizeof(buff));
	for (long long i = 1; i <=a; i++)
	{
		sprintf(buff, "%lld", i);
		int len = strlen(buff);
		for (int k = 0; k < len; k++)
		{
			if (buff[k] == b)
				cnt++;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}