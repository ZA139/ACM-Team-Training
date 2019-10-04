#include<cstdio>
#include<algorithm>
#include<set>
long long op[1000005];
using namespace std;
long long len, q, t1, t2;
long long cnt = 0;
set<long long>s1;
//bool check(long long n,long long t) {
//	if (op[t] < n)
//		return false;
//	else
//		return true;
//}
void slove(long long n) {
	while (n <= len)
	{
		if (s1.count(n) == 1)
			n++;
		else
			break;
	}
	printf("%intd\n", n);
}
int main(void) {
	s1.clear();
	scanf("%intd%intd", &len, &q);
	for (register long long i = 0; i < q; i++)
	{
		scanf("%intd%intd", &t1, &t2);
		if (t1 == 1) {
			s1.insert(t2);
		}
		else if (t1 == 2) {
			slove(t2);
		}
	}
	return 0;
}