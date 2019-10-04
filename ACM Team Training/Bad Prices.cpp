#include<iostream>
#include<algorithm>
long long num[150005];
using namespace std;
int main(void) {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{	
		long long ans=0;
		long long len;
		cin >> len;
		long long mi = 99999999;
		for (long long i = 0; i < len; i++)
		{
			cin >> num[i];
		}
		for (long long i =len-1; i>=0; i--)
		{
			mi = min(mi, num[i]);
			if (num[i] > mi)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}