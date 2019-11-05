#include<cstdio>
#include<string>
#include<cstring>
char s[2005],ans[2005];
using namespace std;
bool judge(int l, int r) {
	while (l <= r) {
		if (s[l] < s[r])
			return true;
		else if (s[r] < s[l])
			return false;
		l++, r--;
	}
	return true;
}
int main(void) {
	int t;
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; i++)
	{
		scanf("%c", &s[i]);
		getchar();
	}
	int left = 0, right = t - 1;
	int cnt = 0;
	while (left <= right)
	{
		if (s[left] < s[right]) {
			ans[cnt++] = s[left];
			left++;
		}
		else if (s[left] > s[right]) {
			ans[cnt++] = s[right];
			right--;
		}
		else {
			if (judge(left, right)) {
				ans[cnt++] = s[left];
				left++;
			}
			else {
				ans[cnt++] = s[right];
				right--;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%c", ans[i]);
		if ((i + 1) % 80 == 0) {
			printf("\n");
		}
	}

	return 0;
}