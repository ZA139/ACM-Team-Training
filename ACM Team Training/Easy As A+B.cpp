#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int a[100000000];
int main(void) {
	int T, N;
	cin >> T;
	while (T--)
	{
		bool first = true;
		int i = 0;
		cin >> N;
		int temp = N;
		while (N--)
		{
			cin >> a[i];
			i++;
		}
		sort(a, a + temp);
		for (int k = 0; k < temp; k++)
		{
			if (first)
			{
				printf("%d", a[k]);
				first = false;
			}
			else
			printf(" %d",a[k]);
		}
		printf("\n");
	}
	return 0;
}


	vector<pair<int, int>> vtMap;

	for (auto it = iMap.begin(); it != iMap.end(); it++)

		vtMap.push_back(make_pair(it->first, it->second));





	sort(vtMap.begin(), vtMap.end(),

		[](const pair<int, int> &x, const pair<int, int> &y) -> int {

		return x.second < y.second;

	});





	for (auto it = vtMap.begin(); it != vtMap.end(); it++)

		cout << it->first << ':' << it->second << '\n';

	return 0;

}
