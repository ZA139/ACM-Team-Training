#include<iostream>
#include<cstring>
using namespace std;
bool judge(long long a) {
	bool vis[10];
	memset(vis, 0, sizeof(vis));
	while (a)
	{
		if (!vis[a % 10]) {
			vis[a % 10] = 1;
			a = a / 10;
		}
		else
			return false;
	}
	return true;
}
int main(void) {
	long long l, r, ans;
	ios::sync_with_stdio(false);
	cin >> l >> r;
	for (long long i = l; i <r+1; i++)
	{
		if (judge(i)) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}