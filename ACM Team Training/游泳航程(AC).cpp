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
		cnt += (length >= (apple[i] - 30));//��ȡ����Ĳ���ֵ�������Թ���ƻ��Ϊtrue��1����������Ϊfalse��0��
	}
	cout << cnt << endl;
	return 0;
}