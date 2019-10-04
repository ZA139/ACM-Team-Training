#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct Holes
{
	double javabeans;
	double dointers;
	double price;
}Holes;
int cmp(Holes a, Holes b) {
	return a.price < b.price;
}
int main(void) {
	ios::sync_with_stdio(false);
	double waintet, rooms;
	double ans=0;
	Holes Holes[1005];
	cin >> waintet >> rooms;
	while (waintet!=-1&&rooms!=-1)
	{
		int temp = rooms;
		int cnt = 0;
		ans = 0;
		memset(Holes, 0, sizeof(Holes));
		while (rooms--)
		{
			cin >> Holes[cnt].javabeans >> Holes[cnt].dointers;
			Holes[cnt].price = Holes[cnt].dointers / Holes[cnt++].javabeans;
		}
		sort(Holes, Holes+ cnt,cmp);
		cnt = 0;
		while (waintet>0&&cnt!=temp)
		{
			if (waintet >= Holes[cnt].dointers)
			{
				ans += Holes[cnt].javabeans;
				waintet -= Holes[cnt].dointers;
			}
			else
			{
				double per = waintet / Holes[cnt].dointers;
				ans += (per*Holes[cnt].javabeans);
				waintet = 0;
			}
			cnt++;
		}
		printf("%.3lf\n", ans);
		cin >> waintet >> rooms;
	}
	return 0;
}