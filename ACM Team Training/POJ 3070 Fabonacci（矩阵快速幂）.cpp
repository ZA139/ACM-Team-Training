#include<stdio.h>
struct Matrix {
	long long data[2][2];
}ans1, ans;
Matrix mul(Matrix a, Matrix b) {
	Matrix temp;
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
			temp.data[i][k] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				temp.data[i][j] += (a.data[i][k] * b.data[k][j])%10000;
			}
		}
	}
	return temp;
}

void QuickPower(int N) {
	ans.data[0][0] = ans.data[0][1] = ans.data[1][0] = 1;
	ans.data[1][1] = 0;

	ans1.data[0][0] = ans1.data[0][1] = ans1.data[1][0] = 1;
	ans1.data[1][1] = 0;
	while (N)
	{
		if (N & 1)
			ans1 = mul(ans1, ans);
		ans = mul(ans, ans);
		N >>= 1;
	}
}
int main(void) {
	long long a;
	scanf("%lld", &a);
	while (a != -1)
	{
		if (a == 0)
			printf("0\n");
		else
		{
			QuickPower(a-1);
			printf("%d\n", ans1.data[0][1] % 10000);
		}
		scanf("%lld", &a);
	}
	return 0;
}