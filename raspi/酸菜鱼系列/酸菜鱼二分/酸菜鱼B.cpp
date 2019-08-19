#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
bool check(int a){
	if((a/3+a/2-a/6>=(n+m))&&a/2>=n&&a/3>=m)
		return true;
	else
		return false;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int l=1,r=1000000*3;
	while(l<=r){
		int mid=(l+r)>>1;
	if(check(mid))
		r=mid-1;
	else
		l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
