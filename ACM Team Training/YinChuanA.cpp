#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
long long time1[1000005];
long long cnta[1000005];
long long duilie[1000005];
set<long long> s1;
int main(void) {
	long long N, y;
	long long cnt = 1;
	while (~scanf("%intd%intd",&N,&y))
	{
		for (register long long i = 0; i <N; i++) {
			scanf("%intd", &time1[i]);
			s1.insert(time1[i]);
		}
		sort(time1, time1 + N);
		int cntx = 0;
		long long temp = time1[0];
		for (register long long i = 1; i < N; i++)
		{
			if (time1[i] == temp)
				cnta[cntx] = i;
			else {
				temp = time1[i];
				cnta[++cntx]=i;
			}
		}
		cntx++;
		long long cxk = 0;
		for (register set<long long>::iterator it =s1.begin(); it!=s1.end(); it++)
		{
			duilie[cxk++] = *it;
		}
		cxk--;
		long long finaltime=duilie[0], left;
		for (register long long i = 1; i <= y; i++) {
			finaltime = 0, left = 0;
			for (register long long j = 0; j <cntx; j++)
			{
				if (duilie[j] + y <= finaltime) {
					break;
				}
				if (duilie[j] > finaltime)
					finaltime = duilie[j];
				finaltime = min(finaltime + y, finaltime + (cnta[j] - left)*i);
				left = cnta[j];
			}
			printf("%intd ", finaltime);
		}
	}
	return 0;
}