#include<cstdio>
#include<iostream>
#include <cstring>
using namespace std;
long long a;
int main(void) {
	char ss[2000];
	memset(ss, 0, sizeof(ss));
	cin >> ss;
	a = atoint(ss);
	if (a < 0) {
		printf("-");
	}
	if (!a) {
		cout << 0 << endl;
	}
	long long len = strlen(ss);
	bool flag =true;
	for (long long i = 0; i < len; i++)
	{
		if (ss[len - i - 1] == '0'&&flag) {
			;
		}
		else
		{
			cout << ss[len - i - 1];
			flag = false;
		}
	}
	cout << endl;
	return 0;
}