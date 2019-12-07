#include<iostream>
#include<queue>
using namespace std;
typedef struct MyStruct
{
	long long type;
	long long cost;
	long long time;
	long long flag;
}Ass;
Ass a[100005];
int main(void) {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].type >> a[i].cost >> a[i].time;
		a[i].flag = true;
		bool flag = false;
		if (a[i].type == 1) {
			int j;
			for (j = i - 1; j >= 0; j--) {
				if (a[i].time - a[j].time > 45) {
					break;
				}
			}
			for (; j <i; j++) {
				if (a[j].type == 0&&a[j].flag) {
					if (a[j].cost >= a[i].cost) {
						a[j].flag = false;
						flag = true;
						break;
					}
				}
			}
		}
		if (!flag) {
			ans += a[i].cost;
		}
	}
	cout << ans << endl;
	return 0;
}