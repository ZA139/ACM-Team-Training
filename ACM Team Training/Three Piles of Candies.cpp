#include<iostream>
using namespace std;
void slove() {
	long long a,sum=0;
	for (size_t i = 0; i < 3; i++)
	{
		cin >> a;
		sum += a;
	}
	//if (sum % 2 == 0)
	//{
		cout << sum / 2 << endl;
	//}
	//else
	//{
	//	cout << sum / 2 + 1 << endl;
	//}
	return;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		slove();
	}
	return 0;
}