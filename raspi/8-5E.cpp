#include<cstdio>
#include<cstring>
int main(void){
	long long ans=1,cnta=1;
	char ch;
	ch=getchar();
	while(ch!='\n'&&ch!='\r')
	{
		if(ch=='a'){
			cnta++;
			ch=getchar();
		}
		else if(ch=='b'){
			ans=(ans*cnta)%1000000007;
			while(ch=='b')
				ch=getchar();
			cnta=1;
		}
		else
			ch=getchar();
	}
	ans=(ans*cnta)%1000000007;
	printf("%lld\n",ans-1);
	return 0;
}
