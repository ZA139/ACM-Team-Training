//#include<cstdio>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//long long prime[100000000];
//int isPrime(long long n) {
//	double n_sqrt;
//	if (n == 2 || n == 3) return 1;
//	if (n % 6 != 1 && n % 6 != 5) return 0;
//	n_sqrt = floor(sqrt((float)n));
//	for (int i = 5; i <= n_sqrt; i += 6)
//	{
//		if (n % (i) == 0 | n % (i + 2) == 0) return 0;
//	}
//	return 1;
//}
//long long cnt = 0;
//int main(void) {
//	for (register long long i = 2; i <= 100000000000000; i++) {
//		if (isPrime(i)) {
//			prime[cnt++] = i;
//		}
//	}
//	int t;
//	long long x;
//	scanf("%d", &t);
//	int temp = 0;
//	while (t-- != 1)
//	{
//		scanf("%lld", &x);
//		if (temp == 1) {
//			if (x & 1) {
//				x--;
//			}
//			else
//			{
//				x++;
//			}
//		}
//		if (x & 1) {
//			temp =(x==prime[lower_bound(prime,prime+cnt,x)-prime]);
//		}
//		else
//		{
//			temp = 0;
//		}
//		printf("%d\n", temp);
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int main(void) {
	int t = 0;
	for (int i = 2; i < 100; i++) {
		cout << i << "    " <<( (i & 1) & 1) << endl;
	}
	return 0;
}