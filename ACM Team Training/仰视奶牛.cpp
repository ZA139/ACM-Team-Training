#include<iostream>
#include<cstring>
using namespace std;
long long cows[100010];
int main(void) {
	memset(cows, 0, sizeof(cows));
	ios::sync_with_stdio(false);
	long long a;
	cin >> a;
	for (long long i = 0; i < a; i++) {
		cin >> cows[i];
	}
	for (long long i = 0; i < a; i++) {
		bool found = false;
		for (long long k = i; k < a; k++)
		{
			if (cows[k] > cows[i])
			{
				found = true;
				cout << k + 1 << endl;
				break;
			}
		}
		if (!found)
			cout << 0 << endl;
	}
	return 0;
}