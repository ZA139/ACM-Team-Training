	#include <iostream>
	#include <cstring>
	double foot, distance1;
	using namespace std;
	int main(void) {
		foot = 7;
		const double rate = 0.98;
		int x;
		double done = 0.0;
		cin >> distance1 >> x;
		while (done<=distance1+x)
		{
			if (done >= distance1 - x&&done<distance1+1) {
				if (done + foot <= distance1 + x) {
					cout << "y\n";
					return 0;
				}
			}
			done += foot;
			foot = foot * rate;
		}
		cout << "n\n";
		return 0;
	}