#include<iostream>
#include<cstring>
using namespace std;
char a[1000005], b[10005];
int nxt[10005];
long long n, m;
long long KMP(char *a,char*b) {
	int i = 0;
	int j = 0;
	while (i<strlen(a)&&j<strlen(b))
	{
		if (j == -1 || a[i] == b[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nxt[j];
		}
	}
	if (j==strlen(b))
	{
		return i-j+1;
	}
	else
	return -1;
}
//const string wzx = "³¬¼¶ÎÞµÐÂÝÐý´óÉµ±Æ";
void getNext(char * p, int * next)

{
	next[0] = -1;
	int i = 0, j = -1;
	while (i < strlen(p))
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &m);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(nxt, 0, sizeof(nxt));
		getchar();
		for (long long i = 0; i < n; i++)
		{
			scanf("%c", &a[i]);
			if (a[i]==' ')
			{
				scanf("%c", &a[i]);
			}
		}
		getchar();
		for (long long i = 0; i < m; i++)
		{
			scanf("%c", &b[i]);
			if (b[i] == ' ')
			{
				scanf("%c", &b[i]);
			}
		}
		getNext(b, nxt);
		printf("%lld\n", KMP(a,b));
	}
	return 0;
}
