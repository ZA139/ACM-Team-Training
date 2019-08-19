#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(void){
	int a,b,c;
	cin>>a>>b;
	c=a>b?a:b;
	int ans=6-c+1;
	int temp=gcd(6,ans);
	//cout<<temp;
	getchar();
	cout<<ans/temp<<"/"<<6/temp<<endl;
	return 0;
}
	
