#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>, greater<int>> q;
int main(void) {
	int t,c;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &c);
		q.push(c);
	}
	long long ans = 0;
	for (int i = 1; i < t; i++) {
		long long temp = q.top();
		q.pop();
		temp += q.top();
		q.pop();
		ans += temp;
		q.push(temp);
	}
	printf("%lld\n", ans);	
	return 0;
}