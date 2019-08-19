#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
long long O_B1,O_S1,O_C1,P_B,P_S,P_C,money1;
int B=0,S=0,C=0;
char s;
bool check(long long a){
	long long O_B=O_B1;
	long long O_S=O_S1;
	long long O_C=O_C1;
	long long money=money1;
	O_B-=a*B;
	O_S-=a*S;
	O_C-=a*C;
	//cout<<O_B<<endl;
	//cout<<O_S<<endl;
	//cout<<O_C<<endl;
	//getchar();
//getchar();
	if(B&&O_B<0){
		money+=O_B*P_B;
		//cout<<"1MONEY     "<<money;
		if(money<0)
		return false;
		}
	if(S&&O_S<0){
		money+=O_S*P_S;
		//cout<<"2MONEY     "<<money;
		if(money<0)
		return false;
	}
	if(C&&O_C<0){
		money+=O_C*P_C;
		//cout<<"3MONEY     "<<money;
		if(money<0)
		return false;
		}
	if(money>=0)
		return true;
}
int main(void){
	ios::sync_with_stdio(false);
	while(s=getchar()){
		if(s=='\n'||s=='\r')
			break;
		else if(s=='B')
			B++;
		else if(s=='S')
			S++;
		else if(s=='C')
			C++;
	}
	cin>>O_B1>>O_S1>>O_C1;
	cin>>P_B>>P_S>>P_C;
	cin>>money1;
	long long l=1,r=10000000000002;
	while(l<=r){
		long long mid=(l+r)/2;
	if(check(mid))
		l=mid+1;
	else
		r=mid-1;
	}
	printf("%lld\n",r);
	return 0;
}
