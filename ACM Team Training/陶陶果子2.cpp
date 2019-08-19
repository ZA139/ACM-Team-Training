#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	int n, s, a[5000],b,c,cnt=0,ans=0;
	memset(a, 0, sizeof(a));
	cin >> n >> s;
	cin >> b >> c;
	b += c;
	int t = n;
	while (n--)
	{
		cin >> c;
		if (c <= b) {
			cin >> a[cnt++];
		}
		else
		cin >> c;
	}
	sort(a, a + cnt);
	for (int i = 0; i < cnt; i++)
	{
		s -= a[i];
		if(s>=0)
		ans++;
	}
	cout << ans << endl;
	return 0;
}