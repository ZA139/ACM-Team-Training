#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int;
int A, B, C;
int main(void) {
	int t;
	scanf("%intd", &t);
	while (t--)
	{
		scanf("%intd%intd", &A, &B);
		if (A&B) {
			printf("%intd\n", A&B);
		}
		else
			printf("1\n");
	}
	return 0;
}