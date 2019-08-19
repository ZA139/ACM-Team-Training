#include<iostream>
using namespace std;
int gcd(int a,int b){
	return b==0? a:gcd(b,a%b);
}
int main(void){
	int a,b,n;
	cin>>a>>b>>n;
	//cout<<gcd(a,n);
	while(1)
	{
		int t=gcd(a,n);
		if(t>n){
			cout<<"1\n";
			break;
		}
		n-=t;
		t=gcd(b,n);
		if(t>n){
			cout<<"0\n";
			break;
		}
		n-=t;
	}
	return 0;
}
