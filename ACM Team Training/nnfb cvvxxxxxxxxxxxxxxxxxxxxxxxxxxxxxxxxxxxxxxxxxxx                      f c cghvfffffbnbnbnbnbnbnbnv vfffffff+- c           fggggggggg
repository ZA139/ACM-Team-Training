#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct Holes
{
	double javabeans;
	double dollers;
}Holes;
int cmp(Holes a, Holes b) {
	return a.javabeans > b.javabeans;
}
int main(void) {
	ios::sync_with_stdio(false);
	double wallet, rooms;
	double ans = 0;
	Holes Holes[1005];
	cin >> wallet;
	while (wallet !=0)
	{
		cin >> rooms;
		int temp = rooms;
		int cnt = 0;
		ans = 0;
		memset(Holes, 0, sizeof(Holes));
		while (rooms--)
		{
			cin >> Holes[cnt].javabeans >> Holes[cnt].dollers;
			cnt++;
		}
		sort(Holes, Holes + cnt, cmp);
		cnt = 0;
		while (wallet > 0 && cnt != temp)
		{
			if (wallet >= Holes[cnt].dollers)
			{
				ans += Holes[cnt].javabeans*Holes[cnt].dollers;
				wallet -= Holes[cnt].dollers;
			}
			else
			{
				ans += Holes[cnt].javabeans*wallet;
				break;
			}
			cnt++;
		}
		/*printf("%.0lf\n", ans);*/
		cout << ans << endl;
		cin >> wallet;
	}
	return 0;
}