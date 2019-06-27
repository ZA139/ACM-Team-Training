#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a[3],d,cnt=0;
	for (size_t i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	cin >> d;
	sort(a, a + 3);
	while (a[1]-a[0]<d)
	{
		cnt++;
		a[0]--;
	}
	while (a[2]-a[1]<d)
	{
		cnt++;
		a[2]++;
	}
	cout << cnt << endl;
	return 0;
}