#include<iostream>
#include<algorithm>
using namespace std;
long long nums[100005];
int t;
bool check(long long a) {
	long long ans = 0;
	for (int i = 0; i < t; i++)
		ans += a-nums[i];
	return ans >= a;
}
int main(void) {
	long long temp = 0;
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> nums[i];
		temp = max(temp, nums[i]);
	}
	long long l = temp, r = 9999999999999;
	while (l<=r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid-1;
		}
		else
			l = mid+1;
	}
	cout << l << endl;
	return 0;
}