#include<iostream>
using namespace std;
int apple[10];
int main(void) {
	int a = 10, length, cnt = 0;
	ios::sync_with_stdio(false);
	while (a--)
	{
		cin >> apple[a];
	}
	cin >> length;
	for (size_t i = 0; i < 10; i++)
	{
		cnt += (length >= (apple[i] - 30));//读取结果的布尔值，即可以够到苹果为true（1），不能则为false（0）
	}
	cout << cnt << endl;
	return 0;
}