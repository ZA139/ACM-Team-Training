#include<iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	int t = 0;
	cin >> t;
	while (t--)
	{
		long long a, b,i;
		cin >> a >> b;
		for ( i = 0; i < 9973; i++)
			if ((((b % 9973)*i) % 9973 - a) % 9973 == 0)

			{
				break;
			}
			cout << i << endl;

	}
	return 0;
}