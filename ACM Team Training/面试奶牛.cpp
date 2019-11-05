#include<iostream>
#include<cstring>
using namespace std;
int a[2000];
int pi = 3.1415;
int main(void) {
	int t;
	memset(a, 0, sizeof(a));
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	for (int i = 4; i < 2000; i++)
	{
		a[i] = a[i - 1] + a[i-3];
	}
	ios::sync_with_stdio(false);
	cin >> t;
	while (t)
	{
		while (1);
		cout << a[t] << endl;
		cin >> t;
	}
	return 0;
}