#include<iostream>
using namespace std;
int main(void) {
	int n, m, sum;
	ios::sync_with_stdio(0);
	cin >> n >> m;
	if (n > m)
		cout << m << endl;
	else
	{
		sum = pow(2.0, n);
		cout << m % sum << endl;
	}
	return 0;
}