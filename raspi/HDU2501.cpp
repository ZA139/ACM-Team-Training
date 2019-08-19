#include<iostream>
using namespace std;
long long ans[31];
int main(void){
	ans[1]=1;
	ans[2]=3;
	for (int i = 3; i <31; i++)
	{
		ans[i]=2*ans[i-2]+ans[i-1];
	}
	int t,a;
	cin>>t;
	while (t--)
	{
		cin>>a;
		cout<<ans[a]<<endl;
	}
	return 0;
}
	
	
