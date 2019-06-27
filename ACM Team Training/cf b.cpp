#include <iostream>
#include <cstring>
#include <algorithm>
bool cmp(long long a,long long b)
{
	return a > b;
}
using namespace std;
long long numbers[105];
bool judge[105];
int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin >> a;
	while (a--)
	{
		int n, cnt = 0, cnt1 = 0;
		memset(judge, 0, sizeof(judge));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> numbers[i];
		}
		sort(numbers, numbers + n, cmp);
		for (int i = 0; i < n; i++)
		{
			if (numbers[i] % 3 == 0)
			{
				judge[i] = 1;
				cnt++;
			}
		}
		int i = 0, j = 1;
		for (i=0;i<n;i++)
			{
				if (!judge[i])
				{
					for (j=i+1;j<n;j++)
					{
						if (!judge[j])
						{
							judge[j] = 1;
							numbers[i] += numbers[j];
							if (numbers[i]%3==0)
							{
								cnt++;
								judge[i] = 1;
							}
						}
					}
					if (i == n - 1 && j == n - 1)
					{
						break;
					}
				}
			}
		
		cout << cnt << endl;
		
	}
	return  0;
}