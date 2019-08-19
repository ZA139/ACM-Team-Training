#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double pie=acos(-1.0);
const double eps=1e-7;
double cake[10005];
int N,F;
double cal(double r){
	return (r*r*pie);
}
bool check(double r){
	int ans=0;
	for (int i = 0; i < N; i++)
	{
		ans+=(int)(cake[i]/r);
	}
	if(ans>=F)
		return true;
	else	
		return false;
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cake,0,sizeof(cake));
		scanf("%d%d",&N,&F);
		F++;
		for (int i = 0; i < N; i++)
		{
			scanf("%lf",&cake[i]);
			cake[i]=cal(cake[i]);
		}
		sort(cake,cake+N);
		double l=0.0;
		double r=cake[N-1];
		while(l+eps<r){
			double mid=(l+r)/2;
			if(check(mid))
				l=mid;
			else 
				r=mid;
		}
		printf("%.4lf\n",r);
	}
	return 0;
}
		
		
