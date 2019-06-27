#include<stdio.h>
#include<set>
#include<vector>
#include<queue>
#define MAX 99999999999;
typedef long long ll;
using namespace std;
/*bool judge(ll num) {
	while (num >= 2)
	{
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else return false;
	}
	if (num == 1)
		return true;
}
int main(void) {
	ll num = 1;
	int counts = 1;
	while (counts!=1000)
	{
		num++;
		if (judge(num))
		{
			counts++;
		}
	}
	printf("The 1500'th ugly number is %lld.", num);
	return 0;
}*/
int main(void)
{
	int multiplier[3] = { 2,3,5 };
	priority_queue <ll, vector <ll>, greater<ll>> pq;
	set <ll> s;
	//set ≤È÷ÿ
	s.insert(1);
	pq.push(1);
	int counts = 1;
	while (1)
	{
		ll temp = pq.top();
		pq.pop();
		if (counts == 1500) {
			printf("The 1500'th ugly number is %lld.\n", temp);
			break;
		}
		for (size_t i = 0; i < 3; i++)
		{
			ll temp2 = temp * multiplier[i];
			if (!(s.count(temp2)))
			{
				s.insert(temp2);
				pq.push(temp2);
			}
		}
		counts++;
	}
	return 0;
}