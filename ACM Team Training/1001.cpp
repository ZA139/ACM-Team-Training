	#include<cstdio>
	#include<cstring>
	#include<iostream>
	#include<string>
	#include <vector>
	using namespace std;
	const int N = 3005;
	long long m[N][N];
	vector<int>v[N];
	bool map[N];
	void slove(int a) {
		map[a] = 1;
		for (vector<int>::iterator it=v[a].begin(); it!=v[a].end(); it++)
		{
			if (!map[*it]) {
				slove(*it);
			}
		}
		return;
	}
	int main(void) {
		int t, k;
		int temp;
		memset(map, 0, sizeof(map));
		long long cnt = 1, ans = 0;
		scanf("%d", &t);
		scanf("%d", &k);
		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < t; j++)
			{
				scanf("%intd", &m[i][j]);
				if (m[i][j] >= k) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for (int i = 0; i <t; i++)
		{
			if (!map[i])
			{
				slove(i);
				ans++;
			}
		}
		for (int i = 0; i < t; i++)
		{
			if (!map[i])
				ans++;
		}
		printf("%intd\n", ans);
		return 0;
	}