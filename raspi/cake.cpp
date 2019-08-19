#include<cstdio>
int N,M,ans=0;
void dfs(int m,int vol,int a,int radius,int height){
	if(m*(radius-1)*(radius-1)*(height-1)<vol&&m!=M)
		return;
	if(vol<0)
		return;
	if(ans&&a>ans)
		return;
	if(!m)
	{
		if(!vol&&(a<ans||!ans))
		ans=a;
	return;
	}
	for (int r = radius-1; r>=m ; r--)
	{
		for (int h = height-1; h>=m ; h--)
		{
			int curvol=r*r*h;
			int cursquare=2*r*h;
			if(m==M) cursquare+=r*r;
			if(a+2*vol/r>ans&&ans)
				continue;
			dfs(m-1,vol-curvol,a+cursquare,r,h);
		}
	}
}
int main(void){
	scanf("%d%d",&N,&M);
	ans=0;
	dfs(M,N,0,100,1000);
	printf("%d\n",ans);
	return 0;
}
	
