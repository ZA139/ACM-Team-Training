#include<iostream>
#include<cmath>
using namespace std;
bool judge_Pal[100000005];
long long reverse1, temp;
bool palindromeNumber(long long num) {
	reverse1 = 0;
	temp = num;
	while (temp > 0) {
		reverse1 = reverse1 * 10 + temp % 10;
		temp = temp / 10;
	}
	return reverse1 == num;
}
int main(void) {
	//freopen("txt.txt", "w", stdout);
	judge_Pal[1] = judge_Pal[0] = true;
	memset(judge_Pal, 0, sizeof(judge_Pal));
	ios::sync_with_stdio(false);
	long long a,b;
	cin >> a >> b;
	long long temp = sqrt(b + 0.5);
	for (long long  i = 2; i <=temp; i++)
	{
		if(!judge_Pal[i])
		for (long long j = i*i; j <= b; j += i)
			judge_Pal[j] = 1;
	}
	for (long long i = a; i <= b; i++)
	{
		if (!judge_Pal[i])
		{
			if (palindromeNumber(i))
			{
				printf("%lld",i);
			}
		}
	}
	return 0;
}