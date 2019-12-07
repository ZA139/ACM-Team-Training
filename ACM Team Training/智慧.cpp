#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, i;
	printf("Please input a num:");
	scanf("%d",&n);
	printf("%d's prime factors are:\n", n);
	//1肯定不是质因子（因为它不满足质数）
	for (i = 2; i <= n/2; i++)
	{
		//如果是因子，进入判断是否是质数
		if (n%i == 0){
			bool flag = true;// 假设一开始它是质数
			for (int j = 2; j <= sqrt(i); j++) {
				if (i%j == 0) {//如果发现它可以被除了1和它本身之外的数整除
					flag = false;//那么它不是质数
					break;//跳出循环
				}
			}
			if(flag)//如果之前没有发现它可以被1和它本身之外的数整除
			printf("%d ", i);//则输出这个数
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