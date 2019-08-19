#include<cstdio>
#include<iostream>
using namespace std;
int main(void){
	long long n=0,ans=1;
	scanf("%lld",&n);
	if(n<10)
		ans--;
	n++;
	
	while(n>10)
	{
		while(n%10)
		{	
			ans++;
			//cout<<n<<endl;	
			n++;
		}
		n/=10;
		//if(n%10){
			//ans++;
			//cout<<n<<endl;	
		//}
	}
	printf("%lld\n",ans+9);
	return 0;
}
