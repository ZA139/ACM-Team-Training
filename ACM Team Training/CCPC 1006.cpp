#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning (disable : 4996)
const int maxn = 1e5 + 100;
struct node {
	int x;
	int y;
	int z;
}num[maxn];
bool cmp(node a, node b) {
	if (a.y == b.y)
		return a.z > b.z;
	return a.y < b.y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i].x);
		num[i].y = i;
	}
	int cnt = 0;
	while (m--) {
		int a;
		scanf("%d", &a);
		num[a].y = 1;
		num[a].z = cnt;
		cnt++;
	}
	sort(num + 1, num + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		printf("%d", num[i].x);
		printf(" ");
	}
	//system("pause");
	return 0;
}
