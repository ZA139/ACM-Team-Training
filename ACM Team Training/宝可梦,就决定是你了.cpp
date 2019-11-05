#include<iostream>
using namespace std;
int main(void) {
	long long n;
	cin >> n;
	long long sum = 1;
	for (long long i = 2; i < n; i++) {
		sum += i;
	}
	sum *= 2;
	sum += n;
	cout << sum << endl;
	return 0;
}