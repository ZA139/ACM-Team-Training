#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string, int> ma;
int main(void) {
	string s,m,n,tar;
	int t,h;
	ios::sync_with_stdio(false);
	int cnt = 1;
	scanf("%d", &t);
	ma["London"] = 0;
	ma["Moscow"] = 3;
	ma["Beijing"] = 8;
	ma["Washington"] = -5;
	while (t--)
	{
		scanf("%d:", &h);
		cin >>m>> s;
		if (s == "AM") {
			if (h == 12)
				h -= 12;
		}
		else {
			if (h == 12)
				h -= 12;
			h += 12;
		}
		cin >> n;
		cin >> tar;
		h -= ma[n];
		h += ma[tar];
		if (h < 0) {
			if (h < -12)
				cout << "Case " << cnt++ << ": " << "Yesterday " << 12 + h << ":" << m << " PM" << endl;
			else if (h == -12)
				cout << "Case " << cnt++ << ": " << "Yesterday 12:" << m << " PM" << endl;
			else
				cout << "Case " << cnt++ << ": " << "Yesterday " << 24 + h << ":" << m << " AM" << endl;
		}
		else if (h == 24)
			cout << "Case " << cnt++ << ": " << "Tomorrow 12:" << m << " AM" << endl;
		else if (h > 24)
		{
			if (h < 36)
				cout << "Case " << cnt++ << ": " << "Tomorrow " << h - 24 << ":" << m << " AM" << endl;
			if (h == 36)
				cout << "Case " << cnt++ << ": " << "Tomorrow 12:" << m << " PM" << endl;
			else
				cout << "Case " << cnt++ << ": " << "Tomorrow " << 12 + h << ":" << m << " PM" << endl;
		}
		else if (h == 0)
			cout << "Case " << cnt++ << ": Today 12:" << m << " AM\n";
		else
		{
			if (h < 12)
				cout << "Case " << cnt++ << ": " << "Today " << h<< ":" << m << " AM" << endl;
			else if (h == 12)
				cout << "Case " << cnt++ << ": " << "Today 12:" << m << " PM" << endl;
			else
				cout << "Case " << cnt++ << ": " << "Today " <<h << ":" << m << " PM" << endl;
		}
	}
	return 0;
}