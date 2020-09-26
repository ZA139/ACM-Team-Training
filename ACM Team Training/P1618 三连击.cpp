#include<algorithm>
#include<iostream>
using namespace std;
int num[10];
long long cal(int a, int b, int c) {
	return num[a] * 100 + num[b] * 10 + num[c];
}
int main(void) {
	bool ans = false;
	for (int i = 0; i < 9; i++) {
		num[i] = i+1;
	}
	long long a, b, c;
	cin >> a >> b >> c;
	long long sum = a * b*c;
	a = sum / a;
	b = sum / b;
	c = sum / c;
	do {
		long long n1 = cal(0, 1, 2)*a, n2 = cal(3, 4, 5)*b, n3 = cal(6, 7, 8)*c;
		if (n1 == n2 && n2 == n3) {
			ans = true;
			cout << num[0] << num[1] << num[2] << " " << num[3] << num[4] << num[5] << " " << num[6] << num[7] << num[8] << endl;
			continue;
		}
	} while (next_permutation(num, num + 9));
	if(!ans)
		cout << "No!!!\n";
	return 0;
}