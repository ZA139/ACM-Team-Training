#include<cstdio>
#define INF 9999999
long long graph[2005][2005];
long long N,M;
void slove(){
	for (int i = 0; i <N ; i++)
	{
		
	}
		
	
	
	
	
	
	
	
	
	
}
int main(void){
	for (int i = 0; i <2005 ; i++)
	{
		for (int j = 0; j <2005 ; j++)
		{
			graph[i][j]=INF;
		}
	}
	scanf("%lld%lld",&N,&M);
	while(M--){
		long long x,y,l;
		scanf("%lld%lld%lld",&x,&y,&l);
		graph[x][y]=l;
		graph[y][x]=l;
	}
	slove();
	return 0;
}
	
