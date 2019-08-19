#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
long long stall[100005];
int N,C;
bool check(long long a){
	long long ans=1,temp=stall[0];
	for (int i = 1; i < N; i++)
	{
		 //std::cout<<i<<":"<<stall[i]-temp<<std::endl;
		if (stall[i]-temp>=a)
		{
			ans++;
			temp=stall[i];
		}
		
	}
	if (ans>=C)
		return true;
	else
		return false;
	
}
void print(){
	for (int i = 0; i < N; i++)
	{
		std::cout<<i<<":"<<stall[i]<<std::endl;
	}
	return;
}
	
int main(void){
	scanf("%d%d",&N,&C);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld",&stall[i]);
	}
	std::sort(stall,stall+N);
	//print();
	//if(check(2))
		//printf("ass");
	//getchar();
	//getchar();
	long long l=stall[0],r=stall[N-1];
	while(l<=r)
	{
		long long mid=(l+r)/2;
		//std::cout<<mid;
		//getchar();
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%lld\n",r);
	return 0;
}
