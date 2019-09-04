#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int index[100005];
int a[100005];
int b[100005];
/*
set<long long>s;
set<long long>s2;*/
int main(void) {
	memset(index, 0, sizeof(index));
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &index[i]);
	}
	sort(index, index + len);
	for (int i = 0; i < len-1; i++)
	{
		int t;
		scanf("%d", &a[i]);
		//s.erase(t);
		//s2.insert(t);
	}
	sort(a, a + len - 1);
	for (int i = 0; i < len; i++)
	{
		if (a[i] != index[i]) {
			printf("%d\n", index[i]);
			break;
		}
		//if (s.count(index[i]))
			//printf("%d\n", index[i]);
	}
	for (int i = 0; i < len - 2; i++)
	{
		scanf("%d", &b[i]);
		//s2.erase(t);
	}
	sort(b, b + len - 2);
	for (int i = 0; i < len; i++)
	{
		if (b[i] != a[i]) {
			printf("%d\n", a[i]);
			break;
		}
		//if (s2.count(index[i]))
		//	printf("%d\n", index[i]);
	}
	return 0;
}