#include<cstdio>
#include<cctype>
#include<cstring>
char zhangwentaodashuaibi[20][20];
int index1[20][20];
bool a[20][20];
bool b[20][20];
void print(int x, int y) {
	printf("%3d.", index1[x][y]);
	while (zhangwentaodashuaibi[x][y] != '*'&& zhangwentaodashuaibi[x][y] != '\0')
	{
		a[x][y] = 1;
		printf("%c", zhangwentaodashuaibi[x][y++]);
	}
	printf("\n");
	return;
}
void printx(int x, int y) {
	printf("%3d.", index1[x][y]);
	while (zhangwentaodashuaibi[x][y]!='*'&& zhangwentaodashuaibi[x][y]!=0)
	{
		b[x][y] = 1;
		printf("%c", zhangwentaodashuaibi[x++][y]);
	}
	printf("\n"); 
	return;
}
int main(void) {
	bool flag = true;
	int n, m;
	//freopen("txt.txt", "w", stdout);
	int Ccnt = 1;
	while (scanf("%d", &n) && n) {
		if (flag)
			flag = false;
		else
			printf("\n");
		int cnt = 1;
		scanf("%d", &m);
		memset(zhangwentaodashuaibi, 0, sizeof(zhangwentaodashuaibi));
		memset(index1, 0, sizeof(index1));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				scanf("%c", &zhangwentaodashuaibi[i][j]);
			}
			getchar();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				if((((!zhangwentaodashuaibi[i][j - 1]||zhangwentaodashuaibi[i][j-1]=='*') || j - 1 < 0) || ((!zhangwentaodashuaibi[i - 1][j] || zhangwentaodashuaibi[i-1][j] == '*') || i - 1 < 0))&&zhangwentaodashuaibi[i][j]!='*')
				{
					index1[i][j] = cnt++;
				}
			}
		}
		printf("puzzle #%d:\n",Ccnt++);
		printf("Across\n");
		for (int i = 0; i <n; i++)
		{
			for (int j = 0; j < m; j++) {
				if (index1[i][j]&&!a[i][j])
					print(i, j);
			}
		}
		printf("Down\n");
		for (int i = 0; i <n; i++)
		{
			for (int j = 0; j <m; j++) {
				if (index1[i][j]&&!b[i][j])
					printx(i, j);
			}
		}
	}
	return 0;
}