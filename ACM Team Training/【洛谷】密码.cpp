#include<iostream>
#include<ctype.h>
using namespace std;
int main(void) {
	char ch, ans;
	int n;
	cin >> n;
	ch = getchar();
	while (ch == '\r'||ch=='\n') {
		ch = getchar();
	}
	while (isalpha(ch))
	{
		ch = toupper(ch) + n;
		if (ch > 'Z')
		{
			ch -= 26;
		}
		printf("%c", tolower(ch));
		ch = getchar();	
	}
	return 0;
}