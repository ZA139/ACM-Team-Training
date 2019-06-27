#include<iostream>
using namespace std;
int main(void) {
	long long cnt=1, cnt2=1;
	char ch;
	ch = getchar();
	while (ch!='\n')
	{
		cnt *= (ch - 'A' + 1);
		ch = getchar();
	}
	ch = getchar();
	while (ch!='\n')
	{
		cnt2 *= (ch- 'A' + 1);
		ch = getchar();
	}
	if ((cnt%47)==(cnt2%47))
	{
		cout << "GO" << endl;
	}
	else
	{
		cout << "STAY" << endl;
	}
	return 0;
}