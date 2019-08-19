#include <iostream>
using namespace std;
int m[100000000];
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
int main() {
	//freopen("txt.txt", "w", stdout);
	int n, a, b, c, d, e, f, g, h, i, j, l = 1,temp,y,dtemp;
	cin >> n;
	dtemp = n;
	if (n > 30 || n < 10)
		cout << 0 << endl;
	temp = n - 10;
	n -= 10;
	temp /= 10;
	n -= temp * 10;
	long long ans = (factorial(10) / (factorial(n)*factorial((10 - n))));
	for (a = 1; a <= 3; a++)
		for (b = 1; b <= 3; b++)
			for (c = 1; c <= 3; c++)
				for (d = 1; d <= 3; d++)
					for (e = 1; e <= 3; e++)
						for (f = 1; f <= 3; f++)
							for (g = 1; g <= 3; g++)
								for (h = 1; h <= 3; h++)
									for (i = 1; i <= 3; i++)
										for (j = 1; j <= 3; j++)
											if (a + b + c + d + e + f + g + h + i + j ==dtemp) {
												m[l] = a;
												l++;
												m[l] = b;
												l++;
												m[l] = c;
												l++;
												m[l] = d;
												l++;
												m[l] = e;
												l++;
												m[l] = f;
												l++;
												m[l] = g;
												l++;
												m[l] = h;
												l++;
												m[l] = i;
												l++;
												m[l] = j;
												l++;
											}
	cout <<ans << endl;
	a = 0;
	for (i = 1; i <= ans * 10; i++) {
		cout << m[i];
		a++;
		if (a % 10 == 0)cout << endl;
		else
		{
			cout << " ";
		}
	}
	return 0;
}