#include<cstdio>
long long score[] = { 0,0,1,3 };
int main(void) {
	long long r, g, b;
	while (~scanf("%intd%intd%intd",&r,&g,&b) ){
		long long ans = 0;
		long long front = 0, behind = 0;
		if (r) {
			front++;
			r--;
		}
		if (g) {
			front++;
			g--;
		}
		if (b) {
			front++;
			b--;
		}
		if (r) {
			behind++;
			r--;
		}
		if (g) {
			behind++;
			g--;
		}
		if (b) {
			behind++;
			b--;
		}
		ans += score[front];
		ans += front * behind + score[behind];
		ans += (front + behind)*(r + b + g);
		printf("%intd\n", ans);
	}

	return 0;
}