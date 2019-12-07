#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
	long long n;
	cin >> n;
	long long temp = n * 2,ans=0;
	bool flag = false;
	int cnt = 0;
	while (temp)
	{
		if (temp % 10 != 9)
			flag = true;
		cnt++;
		temp /= 10;
	}
	long long tar = 0;
	cnt--;
	if (cnt) {
		while (cnt--)
		{
			tar *= 10;
			tar += 9;
		}
		long long mid = (tar + 1) / 2;
		long long tt = tar;
		if (n < tar) {
			tar = n;
		}
		tt++;
		ans += tar - mid + 1;
		if (n > tt)
			ans += n - tt;
		if (!flag)
			ans--;
		cout << ans << endl;
	}
	else
		cout << (n - 1)*n / 2 << endl;
	return 0;
}