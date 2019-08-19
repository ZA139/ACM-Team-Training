#include<cstdio>
double pow(long double a,int b){
	double ans=a;
	for (int i = 1; i <b ; i++)
	{
		ans*=a;
	}
	return ans;
}
using namespace std;
int main(void)
{
	double H,L;
	scanf("%lf%lf",&H,&L);
	double ans=(pow(L,2)-pow(H,2))/(2*H);
	printf("%.13lf\n",ans);
	return 0;
}
