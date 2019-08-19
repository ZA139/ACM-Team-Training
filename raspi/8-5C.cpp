#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	int a,t;
	cin>>t;
	while(t--){
	cin>>a;
	long long ans=pow(2,a-1)+pow(2,a-2)*(a-1);
	cout<<ans<<endl;
	}
	return 0;
}
	
