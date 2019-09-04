#include<iostream>
#include<cmath>
using namespace std; 
long long ans = 0;
long long temp;
inline void slove(long long i) {
	ans = 0;
	temp = i;
	while (i)
	{
		ans += pow(i % 10,10);
		if (ans > temp)
			return;
		i /= 10;
	}
	if (ans == temp)
		cout << temp << ",";
}
int main(void) {
	freopen("txt.txt", "w", stdout);
	for (register long long  i = 4231666762; i < 100000000000; i++)
	{
		slove(i);
		break;
	}
	return 0;
}