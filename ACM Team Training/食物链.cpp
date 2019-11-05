#include<iostream>
#include<algorithm>
using namespace std;
long long gamers[100005];
int n;
bool check(long long x) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (x - gamers[i]);
	}
	return sum >= n;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	long long ma = 0;
	for (int i = 0; i < n; i++) {
		cin >> gamers[i];
		ma = max(ma, gamers[i]);
	}
	long long left = ma, right = 9999999999999;
	while (left <= right) {
		long long mid = (left + right) >> 1;
		if (check(mid)) {
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left << endl;
	return 0;
}