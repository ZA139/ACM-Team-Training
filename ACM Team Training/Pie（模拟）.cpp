#include<iostream>//极端复杂情况不可取
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double cake[10010];
const double pie = acos(-1.0);
double ca(double r) {
	return (pie*r*r);
}
int main(void) {
	long long t,N,F;
	scanf("%lld", &t);
	while (t--)
	{
		memset(cake, 0, sizeof(cake));
		scanf("%lld%lld", &N, &F);
		F++;
		for (int i = 0; i < N; i++)
		{
			scanf("%lf", &cake[i]);
		}
		sort(cake, cake + N);
		if (N >= F)
		{
			printf("%.4lf\n", ca(cake[N-F]));
		}
		else
		{
			int temp = F/N;
			int last = F % N;
			int t = last;
			if (N==1||last==0)
			{
				last = 1;
			}
			if (t)
			{
				temp++;
			}
			double temp_ans = ca(cake[N - last]) / temp;
			
				if (temp_ans > ca(cake[0]))
				{
					temp_ans = ca(cake[0]);
				}
			printf("%.4lf\n",temp_ans );
		}
	}
		return 0;
}