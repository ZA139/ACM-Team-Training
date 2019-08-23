#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char s[1000];
char matrix[105][105];
int cnt;
char a[105][105];
inline void slove(int i) {
	if (!(i & 1)) {
		for (int x = i; x>=0; x--)
		{
			for (int y = 0; y <= i; y++)
			{
				if (x + y == i&&matrix[x][y]!='\0') {
					s[cnt++] = matrix[x][y];
				}
			}
		}
	}
	else
	{
		for (int x = 0; x <= i; x++)
		{
			for (int y = i; y >=0; y--)
			{
				if (x + y == i && matrix[x][y] != '\0') {
					s[cnt++] = matrix[x][y];
				}
			}
		}
	}
}
void print(int t) {
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	int t;
	while (~scanf("%d", &t)) {
		cnt = 0;
		memset(matrix, 0, sizeof(matrix));
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		for (int i = 0; i < t; i++)
		{
			scanf("%s", matrix[i]);
		}
		for (int i = 0; i <= 2 * (t - 1); i++)
		{
			slove(i);
		}
		int tot = 0;
		int x = 0, y = 0;
		while (tot < t*t)
		{
			while (y < t && a[x][y] == '\0') 
				a[x][y++] = s[tot++];
			y--;
			x++;
			while (x < t && a[x][y]=='\0') 
				a[x++][y] = s[tot++];
			x--;
			y--;
			while (y >= 0 && a[x][y] == '\0') 
				a[x][y--] = s[tot++];
			//print(t);
			y++;
			x--;
			while (x>= 0 && a[x][y] == '\0') 
				a[x--][y] = s[tot++];
			x++;
			y++;
		}
		print(t);
	}
	return 0;
}