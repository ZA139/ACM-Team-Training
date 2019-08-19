#include<iostream>
#include<string>
using namespace std;
string a, b;
int main(void) {
	ios::sync_with_stdio(false);
	/*cin.tie(0);
	cout.tie(0);*/
	/*char c;*/
	int ans;
	cin >> a;
	while (a!="#")
	{
		cin >> b;
		ans = 0;
		
		int len = b.length();
		int len2 = a.length();
		for (int i = 0; i <= len2-len; i++)
		{
			string s = a.substr(i, len);
			if (a.substr(i,len)==b)
			{
				ans++;
				i+=len - 1;
			}
		}
		cout << ans << endl;
		a.clear();
		b.clear();
		cin >> a;
	}
	return 0;
}