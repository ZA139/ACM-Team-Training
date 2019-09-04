#include<iostream>
using namespace std;
int main(void) {
	int t, c1=0, c2=0, a;
	cin >> t;
	while (t--)
	{
		cin >> a;
		if (a & 1)
			c1++;
		else
			c2++;
	}
	cout <<( c1 > c2 ? c2 : c1) << endl;
	return 0;
}