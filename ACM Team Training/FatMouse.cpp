#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct Holes
{
	double javabeans;
	double dollers;
	double price;
}Holes;
int cmp(Holes a, Holes b) {
	return a.price < b.price;
}
int main(void) {
	ios::sync_with_stdio(false);
	double wallet, rooms;
	double ans=0;
	Holes Holes[1005];
	cin >> wallet >> rooms;
	while (wallet!=-1&&rooms!=-1)
	{
		int temp = rooms;
		int cnt = 0;
		ans = 0;
		memset(Holes, 0, sizeof(Holes));
		while (rooms--)
		{
			cin >> Holes[cnt].javabeans >> Holes[cnt].dollers;
			Holes[cnt].price = Holes[cnt].dollers / Holes[cnt++].javabeans;
		}
		sort(Holes, Holes+ cnt,cmp);
		cnt = 0;
		while (wallet>0&&cnt!=temp)
		{
			if (wallet >= Holes[cnt].dollers)
			{
				ans += Holes[cnt].javabeans;
				wallet -= Holes[cnt].dollers;
			}
			else
			{
				double per = wallet / Holes[cnt].dollers;
				ans += (per*Holes[cnt].javabeans);
				wallet = 0;
			}
			cnt++;
		}
		printf("%.3lf\n", ans);
		cin >> wallet >> rooms;
	}
	return 0;
}