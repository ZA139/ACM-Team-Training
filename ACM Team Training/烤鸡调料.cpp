#include<iostream>
#include<stack>
using namespace std;
stack<int>s;
int arrays[10] = { 0 }, temp, dtemp;
long long factorial(int a) {
	if (!a)
		return 1;
	long long sum = 1;
	for (int i = 1; i <= a; i++)
	{
		sum *= i;
	}
	return sum;
}
void print(int b) {
	/*int t = a;*/
	for (int i = b; i < 1;)
	{
		arrays[i]++;
		dtemp--;
		i++;
		if (dtemp > 0)
			print(i);
		else
		{
			break;
		}
	}
}
int main(void) {
	int a = 0;
	ios::sync_with_stdio(false);
	cin >> a;
	if (a > 30 || a < 10)
		cout << 0 << endl;
	temp = a - 10;
	a -= 10;
	temp /= 10;
	a -= temp * 10;
	dtemp = a;
	long long n = (factorial(10) / (factorial(a)*factorial((10 - a))));
	for (size_t i = 0; i < 10; i++)
	{
		arrays[i]++;
		arrays[i] += temp;
	}
	print(0);
	for (size_t k = 0; k < 10; k++)
	{
		cout << arrays[k] << " ";
	}
	cout << endl;
	cout << n << endl;
	return 0;
}