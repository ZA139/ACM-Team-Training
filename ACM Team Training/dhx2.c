#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void) {
	int a[10];
	int max = 0,min = 101,count=0;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		a[i] = rand()%100+1;
		if (max < a[i]) {
			max = a[i];
		}
		if (min > a[i]) {
			min = a[i];
		}
		if (a[i] % 5 == 0) {
			count++;
		}
	}
	printf("max=%d\nmin=%d\ncount=%d\n", max, min, count);
	return 0;
}