#include<iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			long long temp;
			cin >> temp;
			sum += temp;
		}
		long long ans = 0;
		if (sum%n)
			ans++;
		ans += sum / n;
		cout << ans << endl;
	}
	return 0;
}