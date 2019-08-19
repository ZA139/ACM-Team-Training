#include<cstdio>
int main(void){
	int n=0;
	bool ans=true;
	scanf("%d",&n);
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			if(i%j==0&&i*j>n)
			{
				double divide=i/j;
				if(divide<n)
					{
						printf("%d %d\n",i,j);
						ans=false;
						break;
					}
			}
		}
		if(!ans)
			break;
	}
	if(ans)
		printf("-1\n");
	return 0;
}
