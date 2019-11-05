#include<cstdio>
#include<cstring>
int v[10];
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(v, 0, sizeof(v));
		int r;
		for (int i = 0; i < 5; i++) {
			scanf("%d", &r);
			v[r]++;
		}
		int ans = -1, max = 0;
		for (int i = 0; i < 5; i++) {
			if (v[i] > max) {
				ans = i;
				max = v[i];
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}