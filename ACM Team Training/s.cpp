#include<ctype.h>
#include<string.h>
#include<stdio.h>
int main(void) {
	long long nums[10000];
	printf("请输入数字,使用空格隔开，以回车结尾\n");
	memset(nums, 0, sizeof(nums));//初始化nums数组
	long long cnt = 0;
	long long temp = 0;
	char ch;
	ch = getchar();
	while (ch!='\n')
	{
		if (isdigit(ch)) {//如过读到数字则进位
			nums[cnt] *= 10;
			nums[cnt] += (ch - '0');
		}
		else if (ch == ' ')//如果读到空格则这个数字结束
		{
			cnt++;
		}
		ch = getchar();
	}
	printf("您输入了%lld个数字\n", cnt);
	printf("您输入的数字为：\n");
	for (int i = 0; i <=cnt; i++) {
		printf("%lld\n", nums[i]);
	}
	return 0;
}