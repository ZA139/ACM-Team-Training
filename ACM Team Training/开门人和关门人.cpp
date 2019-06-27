#include<iostream>
#include<string.h>
#include<string>
using namespace std;
char a[50], b[50];
string ans1, ans2, input;
int main(void) {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	int n, k;
	cin >> n;
	while (n--)
	{
		char c[] = "23:59:59", d[] = "00:00:00";
		cin >> k;
		while (k--)
		{
			cin >> input >> a >> b;
			if (strcmp(a,c)<0)
			{
				strcpy(c,a);
				ans1 = input;
			}
			if (strcmp(b, d)>0)
			{
				strcpy(d,b);
				ans2 = input;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}