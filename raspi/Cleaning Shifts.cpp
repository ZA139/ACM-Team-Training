#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
struct cow{
	int begin;
	int end;
};
int cmp(cow a,cow b){
	if(a.begin==b.begin)
		return a.end>b.end;
	return a.begin<b.begin;
}
cow mew[25005];
int main(void){
	int N,T;
	scanf("%d%d",&N,&T);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d",&mew[i].begin,&mew[i].end);
	}
	std::sort(mew,mew+N,cmp);
	int sum=0,pos=0,over=0;
	while(over<T)
	{
		int start=over+1;
		for (int i = pos; i <N ; i++)
		{
			if(mew[i].begin<=start){
				over=std::max(over,mew[i].end);
				}
			else{
				pos=i;
				break;
			}
		}
		if(start>over){
			printf("-1\n");
			break;
		}
		else
			sum++;
	}
	if(over>=T)
		printf("%d",sum);
	return 0;
}	
