#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
char s[200005];
int main(void) {
	long long a = 0;
	long long cnt = 0;
	scanf("%lld", &a);
	getchar();
	for (long long i = 0; i < a; i++)
	{
		scanf("%c", &s[i]);

	}
	for (long long i = 0; i+1< a; i+=2) {
		if (s[i] == 'a') {
			if (s[i+1] != 'b') {
				cnt++;
				s[i+1] = 'b';
			}
		}
		else if (s[i] == 'b') {
			if (s[i+1] != 'a') {
				cnt++;
				s[i+1] = 'a';
			}
		}
	}
	printf("%lld\n%s\n", cnt, s);
	return 0;
}