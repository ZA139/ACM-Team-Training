#include<iostream>
using namespace std;
int main(void) {
	long long a, b;
	cin >> a >> b;
	if (a == 0)
	{
		cout << "Austin"<<endl;
	}
	else if (b>1)
	{
		cout << "Adrien" << endl;
	}
	else if(b==1)
	{
		if (a&1)
		{
			cout << "Adrien" << endl;
		}
		else
		{
			cout << "Austin" << endl;
		}
	}
	return 0;
}