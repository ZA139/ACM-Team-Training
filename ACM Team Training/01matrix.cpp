#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<int>height, width;
int matrix[2005][2005];
long long ans;
int main(void)
{
	ios::sync_with_stdio(false);
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++) {
				cin >> matrix[i][k];
			}
		}
	}
}
