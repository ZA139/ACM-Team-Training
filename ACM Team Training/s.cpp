#include<ctype.h>
#include<string.h>
#include<stdio.h>
int main(void) {
	long long nums[10000];
	printf("����������,ʹ�ÿո�������Իس���β\n");
	memset(nums, 0, sizeof(nums));//��ʼ��nums����
	long long cnt = 0;
	long long temp = 0;
	char ch;
	ch = getchar();
	while (ch!='\n')
	{
		if (isdigit(ch)) {//��������������λ
			nums[cnt] *= 10;
			nums[cnt] += (ch - '0');
		}
		else if (ch == ' ')//��������ո���������ֽ���
		{
			cnt++;
		}
		ch = getchar();
	}
	printf("��������%lld������\n", cnt);
	printf("�����������Ϊ��\n");
	for (int i = 0; i <=cnt; i++) {
		printf("%lld\n", nums[i]);
	}
	return 0;
}