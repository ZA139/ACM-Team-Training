#include<cstdio>
#include<cstring>
using namespace std;
long long stones[50010];
//long long distance[50010];
long long N, M, L;
bool check(long long a) {
	int ans=0,t=0;
	for (long long i = 1; i < N+1; i++)
	{
		while (stones[i]-t<a&&i<N+1)//一次性删除连续的小于最小距离的石头
		{
			ans++;
			i++;
		}
		t = stones[i];
	}
	return ans > L ;
}
int main(void) {
	memset(stones, 0, sizeof(stones));
	/*memset(distance, 0, sizeof(distance))*/;
	scanf("%lld%lld%lld", &M, &N, &L);
	stones[0] = 0;
	for (long long  i =1; i <=N; i++)
	{
		scanf("%lld", &stones[i]);
	/*	distance[i] = stones[i] - stones[i - 1];*/
	}
	/*distance[N+1] = M - stones[N];*/
	long long l = 0;
	while (l<=M)
	{
		long long mid = (l + M) >> 1;
		if (!check(mid))
			l = mid + 1;
		else
			M = mid - 1;
	}
	printf("%lld",M);
	return 0;
}