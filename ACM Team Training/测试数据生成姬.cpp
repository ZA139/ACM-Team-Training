#include<iostream>
#include<ctime>
using namespace std;
int main(void) {
	srand(time(0));
	long long n = rand() % 2000;
	printf("%lld\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("%c\n", rand() % 26 + 'A');
	}
	return 0;
}