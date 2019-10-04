#include<iostream>
using namespace std;
long long time[4];
int main(void) {
	for (int i = 1; i <4; i++)
	{
		cin >> time[i];
	}
	int n;
	long long times = 0;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (!a)
			times += b;
		else if (a == 1) {
			times += b;
		}
		else if (a == 2) {
			times += b;
			times += time[1];
		}
	}
	cout << times << endl;
	return 0;
}