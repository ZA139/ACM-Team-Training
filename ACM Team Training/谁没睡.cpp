#include<iostream>
using namespace std;
int main(void) {
	int a, b, c, d;
	cin >> a>>b;
	int cnt = 0;
	int temp = b;
	while (a--)
	{
		b = temp;
		while (b--)
		{
			cin >> c >> d;
			if (c || d)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}