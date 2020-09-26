#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(void) {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int len = s.length();
		int l = 0, r = 0, u = 0, d = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'L')
				l++;
			if (s[i] == 'R')
				r++;
			if (s[i] == 'U')
				u++;
			if (s[i] == 'D')
				d++;
		}
		l = min(l, r);
		r = l;
		u = min(u, d);
		d = u;
		int sum = l + r + u + d;
		if (l && !u)
		{
			sum = 2;
			printf("%d\n", sum);
			printf("LR\n");
			continue;
		}
		if (!l&&u)
		{
			sum = 2;
			printf("%d\n", sum);
			printf("UD\n");
			continue;
		}
		bool flag = false;
		if (sum == 0)
			flag=true;
		printf("%d\n", sum);
		while (l--)
			printf("L");
		while (u--)
			printf("U");
		while (r--)
			printf("R");
		while (d--)
			printf("D");
		if (flag)
			printf("\n");
		printf("\n");
	}
	return 0;
}
