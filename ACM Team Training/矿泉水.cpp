#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct Holes
{
	long long price;
	long long weights;
	double per;
}Holes;
Holes water[1005];
int cmp(Holes a, Holes b) {
	return a.per < b.per;
}
int main(void) {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &water[i].price, &water[i].weights);
			water[i].per = water[i].price / water[i].weights;
		}
		sort(water, water + n, cmp);
		long long ans = 0, wa = 0;
		
	}
	return 0;
}