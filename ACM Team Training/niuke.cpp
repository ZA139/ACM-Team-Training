#include<cstdio>
#include<cstring>
int len;
char s[100005];
bool check(int l) {
	for (int i = 0; i < l; i++)
	{
		if (s[i] != s[len +i - l]) {
			return false;
		}
	}
	for (int i = l; i < len-l; i++) {
		if (s[i] == s[0]) {
			for (int j = 1; j < l; j++) {
				if (s[i + j] != s[j]) {
					goto x;
				}
			}
			return true;
		}
	x:
		;
	}
	return false;
}
int main(void) {
	scanf("%s", s);
	len = strlen(s);
	int l = 0, r = len, ans = len;
	while (1)
	{
		if (check(ans--)) {
			break;
		}
	}
	for (int i = 0; i <= ans; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}