#include<iostream>
bool judge_Pal[1000005], judge_ans[1000005];
int ans[1000005];
using namespace std;
bool beauty(int a) {
	int sum = 0;
	while (a)
	{
		sum += a%10;
		a /= 10;
	}
	if (!judge_Pal[sum])
		return true;
	else
		return false;
}
int main(void) {
	memset(ans, 0, sizeof(ans));
	memset(judge_ans, 0, sizeof(judge_ans));
	int k = 1;
	memset(judge_Pal, 0, sizeof(judge_Pal));
	int d = sqrt(1000000 + 0.5);
	for (long long i = 2; i <= d; i++)
	{
		if (!judge_Pal[i])
			for (long long j = i * i; j < 1000000; j += i)
				judge_Pal[j] = 1;
	}
	judge_Pal[0] = judge_Pal[1] = 1;
	for (int i = 0; i < 1000000; i++)
	{
		if (!judge_Pal[i])
		{
			if (beauty(i))
			{
				judge_ans[i] = 1;
			}
		}
	}
	freopen("txt.txt", "w", stdout);
	int a, b, c=1;
	//cin >> c;
	while (c--)
	{
		cin >> a >> b;
		int cnt = 0;
		for (int  i = 1; i <=1000020; i++)
		{
			if (judge_ans[i])
			{
				printf("%d,", i);
			}
		}
		printf("Case #%d: %d\n", k++, cnt);
	}
	return 0;
}