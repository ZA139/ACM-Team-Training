#include <cstdio>
#include <cmath>
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char s[200];
		scanf("%s", s);
		int temp = 0;
		for (int i =7; i >=0; i--)
		{
			if (s[i] - '0') {
				temp += pow(2, 8 - i - 1);
			}
		}
		printf("%d.", temp);
		temp = 0;
		for (int i = 7; i >= 0; i--)
		{
			if (s[i + 8] - '0') {
				temp += pow(2, 8 - i - 1);
			}
			
		}
		printf("%d.", temp);
		temp = 0;
		for (int i = 7; i >= 0; i--)
		{
			if (s[i + 16] - '0') {
				temp += pow(2, 8 - i - 1);
			}
			
		}
		printf("%d.", temp);
		temp = 0;
		for (int i = 7; i >= 0; i--)
		{
			if (s[i + 24] - '0') {
				temp += pow(2, 8 - i - 1);
			}
		}
		printf("%d\n", temp);
	}
	return 0;
}