#include<cstdio>
#include<cstring>
const int sticks[10] = { 6,2,5,5,4,5,6,3,7,6 };
int wei[100005];
char ans[100005];
char temp[100005];
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int cnt = 0;
		int num = 1;
		memset(wei, 0, sizeof(wei));
		memset(ans, 0, sizeof(ans));
		memset(temp, 0, sizeof(temp));
		int n;
		long long sum = 0;
		scanf("%d", &n);
		scanf("%s", &temp);
		for (int i = 0; i <n; i++)
		{
			sum += sticks[temp[i] - '0'];
		}
		for (int j = n-1; j >=0; j--)
		{
			for (int i = 9; i >=0; i--)
			{
				long long a = sum - sticks[i];
				if (a >= 2 *(n-num)) {
					if (j == 0) {
						if (a == 0) {
							sum = a;
							ans[cnt++] = '0' + i;
							num++;
							break;
						}
						else
							continue;
					}
					else
					{
						sum = a;
						ans[cnt++] = '0' + i;
						num++;
						break;
					}
				}
			}
		}
		printf("%s\n", ans);
	}
	return 0;
}