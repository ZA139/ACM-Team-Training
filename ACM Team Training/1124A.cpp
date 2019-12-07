#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
ll q[100005];
int main(void) {
	int t;
	cin >> t;
	for (int i = 1; i < 100005; i++) {
		ll temp = i;
		bool ok = true;
		while (temp)
		{
			if (ok&&temp % 3 == 2){
				ok = false;
				break;
			}
			temp /= 3;
		}
		if(ok)
			q[i] = 1;
	}
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = n; i < 100005; i++) {
			if (q[i]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}