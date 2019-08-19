#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(void){
	long long a,b;
	while(~scanf("%lld%lld",&a,&b)){
	if(a>b)
		swap(a,b);
	double c=b-a;
	//cout<<c;
	double x=(1+sqrt(5.0))/2;
	int t=(c*x+c);
	if(t==b)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}
