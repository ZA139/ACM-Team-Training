#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int;
int main(void) {
	int a, b, c;
	scanf("%intd%intd%intd", &a, &b, &c);
	int mi = a-b+1;
	int mx = 1;
	int len = b - 1;
	int temp = 2;
	while (len--&&len>=0)
	{
		mi += temp;
		temp *= 2;
	}
	len = c - 1;
	temp = 1;
	while (len--&&len>=0)
	{
		temp *= 2;
		mx += temp;
	}
	len = a-c;
	while (len--&&len>=0)
	{
		mx += temp;
	}
	printf("%intd %intd\n", mi, mx);
	return 0;
}