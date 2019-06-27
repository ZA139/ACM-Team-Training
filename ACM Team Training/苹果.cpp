#include<iostream>
using namespace std;
int apple[10];//十个苹果
int main(void) {
	int a = 10, length, cnt = 0;
	ios::sync_with_stdio(false);//加快cin,cout的速度
	while (a--)//从apple[9]开始逆序读取苹果高度
	{
		cin >> apple[a];
	}
	cin >> length;
	for (size_t i = 0; i < 10; i++)
	{
		cnt += (length >= (apple[i] - 30));
	}
	cout << cnt << endl;
	return 0;
}