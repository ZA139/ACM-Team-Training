#include<iostream>
using namespace std;
int apple[10];//ʮ��ƻ��
int main(void) {
	int a = 10, length, cnt = 0;
	ios::sync_with_stdio(false);//�ӿ�cin,cout���ٶ�
	while (a--)//��apple[9]��ʼ�����ȡƻ���߶�
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