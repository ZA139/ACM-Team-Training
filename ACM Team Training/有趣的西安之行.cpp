#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
set<long long> s;
int main(void) {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	s.clear();
	while (k--) {
		long long t;
		scanf("%lld", &t);
		if (s.count(t) == 1) {
			s.erase(t);
		}
		else {
			s.insert(t);
		}
		if (s.size() <= 1) {
			printf("-1\n");
		}
		else {
			set<long long>::iterator it1 = s.end();
			it1--;
			set<long long>::iterator it2 = s.begin();
			printf("%lld\n", (*it1) - (*it2));
		}
	}
	return 0;
}