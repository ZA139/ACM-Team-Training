#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
std::string s;
int temp[10000005];
int main(void) {
	memset(temp, 0x3f3f, sizeof(temp));
	int sum = 0;
	int ans = 0, n;
	scanf("%d", &n);
	std::cin >> s;
	sum = n+1;
	temp[sum] = 0;
	for (int i = 0; i <n; i++)
	{
		if (s[i] == '1')
			sum++;
		else if (s[i] == '0')
			sum--;
		temp[sum] = std::min(i+1, temp[sum]);
		ans = std::max(ans, i - temp[sum]+1);
	}
	printf("%d\n", ans);
	return 0;
}