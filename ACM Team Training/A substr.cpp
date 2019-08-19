#include<iostream>
#include<string>
using namespace std;
string s;
int main(void) {
	ios::sync_with_stdio(false);
	int n,m,temp=0;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s.substr(0,i)==s.substr(n-i,i))
		{
			temp = i;
		}
	}
	for (int i = 0; i <m; i++)
	{
		cout << s.substr(0, n - temp);
	}
	cout << s.substr(n - temp, n)<<endl;
	return 0;
}