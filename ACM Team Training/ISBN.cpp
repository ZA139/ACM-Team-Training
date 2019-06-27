#include<iostream>
#include<string>
using namespace std;
char ans[11] = { '0','1','2','3','4','5','6','7','8','9','X'};
int main(void) {
	string s;
	cin >> s;
	int cnt = 0, j = 1;
	for (int i = 0; i < 11; i++)
	{
		if (s[i] == '-')
			continue;
		else
		{
			cnt += (s[i] - '0')*(j++);
		}
	}
	//int a = s[13] - '0';
	if (s[12] == ans[cnt % 11])
		printf("Right\n");
	else if(cnt % 11 == 10)
	{
		s[12] = 'X';
		cout << s << endl;
	}
	else
	{
		s[12] = (cnt % 11)+'0';
		cout << s << endl;
	}
	return 0;
}