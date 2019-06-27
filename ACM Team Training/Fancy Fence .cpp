#include<iostream>
using namespace std;
int main(void) {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		int a;
		cin >> a;
		for (int i = 3;; i++) {
			float angle = ((i - 2) * 180.0)/ i;
			if (a<angle||angle > 180||a<60)
			{
				cout << "NO\n";
				break;
			}
			if (angle == a)
			{
				cout << "YES\n";
				break;
			}
		}
	}
	return 0;
}//角度严格相等注意浮点数