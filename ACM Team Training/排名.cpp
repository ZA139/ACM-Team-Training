#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
struct Node
{
	char name[50];
	long score=0;
}node[1050];

bool cmp(Node a, Node b) {
	if (a.score != b.score)
		return a.score > b.score;
	return strcmp(a.name, b.name) > 0 ? 0 : 1;
}
int score[15];
int main(void) {
	while (1)
	{
		memset(node, 0, sizeof(node));
		int k = 0;
		memset(score, 0, sizeof(score));
		int n, num, line;
		scanf("%d", &n);
		if (!n)
			return 0;
		scanf("%d%d", &num, &line);
		for (int i = 1; i <= num; i++)
		{
			scanf("%d", &score[i]);
		}
		for(int i=0;i<n;i++)
		{
			int num_ac, a;
			scanf("%s%d", &node[k].name, &num_ac);
			for (int i = 0; i < num_ac; i++)
			{
				scanf("%d", &a);
				node[k].score += score[a];
			}
			k++;
		}	int cnt = 0;
		sort(node, node + n, cmp);
		for (int i = 0; i <n; i++)
		{
		
			if (node[i].score >= line)cnt++;
		}
		printf("%d\n", cnt);
		for (int i = 0; i <n; i++)
		{
			if (node[i].score >= line)
			printf("%s %d\n", node[i].name, node[i].score);
		}
	}
	return 0;
}