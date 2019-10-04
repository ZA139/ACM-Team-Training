#include<iostream>
#include<string>
using namespace std;
string s1;
int main(void) {
	ios::sync_with_stdio(false);
	int n,m,temp=0;
	cin >> n >> m;
	cin >> s1;
	for (int i = 0; i < n; i++)
	{
		if (s1.substr(0,i)==s1.substr(n-i,i))
		{
			temp = i;
		}
	}
	for (int i = 0; i <m; i++)
	{
		cout << s1.substr(0, n - temp);
	}
	cout << s1.substr(n - temp, n)<<endl;
	return 0;
}