#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, i;
	printf("Please input a num:");
	scanf("%d",&n);
	printf("%d's prime factors are:\n", n);
	//1�϶����������ӣ���Ϊ��������������
	for (i = 2; i <= n/2; i++)
	{
		//��������ӣ������ж��Ƿ�������
		if (n%i == 0){
			bool flag = true;// ����һ��ʼ��������
			for (int j = 2; j <= sqrt(i); j++) {
				if (i%j == 0) {//������������Ա�����1��������֮���������
					flag = false;//��ô����������
					break;//����ѭ��
				}
			}
			if(flag)//���֮ǰû�з��������Ա�1��������֮���������
			printf("%d ", i);//����������
		}
	}
	return 0; 
}
#include<stdio.h>
#define maxn 100
const int MAXN = 100;
int add(int, int);
int main(void) {
	float x = 0;
	return 0;
}