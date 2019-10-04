#include<stdio.h>
#include<math.h>
int main(void) {
	for (int i = 1; i <=9; i++)//bai
	{
		for (int j = 0; j <= 9; j++)//shi
		{
			for (int k = 0; k <=9; k++)//ge
			{
				if (pow(i, 3) + pow(k, 3) + pow(j, 3) == i * 100 + j * 10 + k)
					printf("%d%d%d\n", i, j, k);
			}
		}
	}
	return 0;
}