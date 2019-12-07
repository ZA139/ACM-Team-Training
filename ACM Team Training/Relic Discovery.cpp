#include<iostream>
using namespace std;
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long sum = 0;
		long long a, b;
		while (n--) {
			cin >> a >> b;
			sum += a * b;
		}
		cout << sum << endl;
	}
	return 0;
}