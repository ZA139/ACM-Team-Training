#include<cstdio>
#include<algorithm>
using namespace std;
struct money
{
	long long num;
	long long ex;
}mod[1000000];
bool cmp(money a, money b) {
	return a.ex < b.ex;
}
int main(void) {
	long long cnt=0;
	long long k = 10000; 
	while (k <= 99000) {
		mod[cnt].num = k;
		mod[cnt++].ex = k * 3 * 0.3 + 21000-k;
		k += 100;
	}
	sort(mod, mod + cnt, cmp);
	for (int i = 0; i < 10; i++) {
		printf("埋下的钱数：%lld        期望收益:%lld\n", mod[i].num, mod[i].ex);
	}
	return 0;
}