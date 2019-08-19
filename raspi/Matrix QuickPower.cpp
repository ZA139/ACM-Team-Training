#include<stdio.h>
struct Matrix {
	long long data[2][2];
}ans1, ans;
long long a,b,c;
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
				temp.data[i][j] += (a.data[i][k] * b.data[k][j])%7;
			}
		}
	}
	return temp;
}

void QuickPower(long long N) {
	ans.data[0][0] = ans.data[0][1]= 1;
	ans.data[1][0] = a;
	ans.data[1][1] = b;

	ans1.data[0][0] = ans1.data[0][1] = 1;
	ans1.data[1][1] = b;
	ans1.data[1][0] = a;
	while (N)
	{
		if (N & 1)
			ans1 = mul(ans1, ans);
		ans = mul(ans, ans);
		N >>= 1;
	}
}
int main(void){
	scanf("%lld%lld%lld",&a,&b,&c);
	while(a&&b&&c){
	QuickPower(c+1);
	printf("%lld\n",ans.data[0][1]%7);
	scanf("%lld%lld%lld",&a,&b,&c);
	}
	return	0;
	}
