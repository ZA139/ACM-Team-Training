#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	vector<int>v;
	int aa = a, bb = b, cc = c, dd = d;
	while (aa&&bb) {
		v.push_back(0);
		v.push_back(1);
		aa--; bb--;
	}
	while (bb&&cc) {
		v.push_back(2);
		v.push_back(1);
		bb--; cc--;
	}
	while (cc&&dd) {
		v.push_back(2);
		v.push_back(3);
		cc--; dd--;
	}
	if (cc) {
		v.push_back(2);
		cc--;
	}
	int flag = 0;
	if (cc == 0 && bb == 0 && dd == 0 && aa == 0) {
		for (int i = 1; i < v.size(); i++) {
			if (v[i] - v[i - 1] == -1 || v[i] - v[i - 1] == 1);
			else flag = 1;
		}
		if (flag == 0) {
			printf("YES\n");
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
			return 0;
		}
	}
	v.clear();
	aa = a, bb = b, cc = c, dd = d;
	while (aa&&bb) {
		v.push_back(1);
		v.push_back(0);
		aa--; bb--;
	}
	while (bb&&cc) {
		v.push_back(1);
		v.push_back(2);
		bb--; cc--;
	}
	while (cc&&dd) {
		v.push_back(3);
		v.push_back(2);
		cc--; dd--;
	}
	if (dd) {
		v.push_back(3);
		dd--;
	}
	if (cc == 0 && bb == 0 && dd == 0 && aa == 0) {
		for (int i = 1; i < v.size(); i++) {
			if (v[i] - v[i - 1] == -1 || v[i] - v[i - 1] == 1);
			else flag = 1;
		}
		if (flag == 0) {
			printf("YES\n");
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
			return 0;
		}
	}
	if (a + b + c + d == 1) {
		if (a)printf("0");
		if (b)printf("1");
		if (c)printf("2");
		if (d)printf("3");
		printf("\n");
	}
	printf("NO\n");
	return 0;
}