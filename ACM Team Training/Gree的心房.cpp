#include<iostream>
using namespace std;
int main(void) {
	long long n, m, k;
	cin >> n >> m >> k;
	if ((n*m - n - m + 1) < k){
		cout << "-1" << endl;
	}
	else
		cout << n + m - 2 << endl;
	return 0;
}