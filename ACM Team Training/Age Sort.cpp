#include<cstdio>
#include<cstring>
int n, nn[105],t;
int main(void) {
	//freopen("txt.txt", "w", stdout);
	while (scanf("%d",&n)&&n)
	{
		bool flag = true;
		memset(nn, 0, sizeof(nn));
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			nn[t]++;
		}
		for (int i = 0; i < 100; i++)
		{
			while(nn[i]--) {
				if (flag) {
					printf("%d", i);
					flag = false;
				}
				else
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}