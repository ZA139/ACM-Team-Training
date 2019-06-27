#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int stone[10010];
int main(void) {
	memset(stone, 0, sizeof(stone));
	int n, q, Case = 1,target;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (scanf("%d%d",&n,&q)==2&&n&&q)
	{
		bool first = true;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &stone[i]);
		}
		sort(stone, stone + n);
		for (int i = 0; i < q; i++)
		{
			
            scanf("%d", &target);
			if (first) {
				printf("CASE# %d:\n", Case++); first = false;
			}
			int num = lower_bound(stone, stone + n, target) - stone;//不小于k的第一个元素的地址
			if(stone[num]==target)
			printf("%d found at %d\n", target,num+1);
			else
			{
				printf("%d not found\n", target);
			}
		}
	}
	return 0;
}