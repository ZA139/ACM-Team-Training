//已知BUG：1.学号排序输出
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int score[2000];

map<string, long long>m;
vector<pair<string, int>> vtMap;
string s1[1500], e;
int main(void) {
	//freopen("txt.txt", "w", stdout);
	while (1)
	{
		vtMap.clear();
		m.clear();
		auto it = s1->begin();
		auto it2 = s1->end();
		s1->erase(it, it2);
		int cnt = 0, k = 0;
		memset(score, 0, sizeof(score));
		long long K, TXT, Line;
		scanf("%intd", &K);
		if (!K)
			return 0;
		scanf("%intd%intd", &TXT, &Line);
		for (int i = 1; i <= TXT; i++)
		{
			scanf("%d", &score[i]);
		}
		while (K--)//考生输入
		{
			cin >> e;
			long long j = 0, score2, total = 0;
			scanf("%intd", &j);
			while (j--)
			{
				scanf("%intd", &score2);
				total += score[score2];
				if (total >= Line)
				{
					m[e] = total;
				}
			}
			if (total >= Line)
				cnt++;
		}
		cout << cnt << endl;

		for (auto it = m.begin(); it != m.end(); it++)

			vtMap.push_back(make_pair(it->first, it->second));
		sort(vtMap.begin(), vtMap.end(),

			[](const pair<string, int> &x, const pair<string, int> &y) -> int {
			if (x.second ==y.second)
			{
				return x.first > y.first;
			}
			else return x.second > y.second;

		});
		for (auto it = vtMap.begin(); it != vtMap.end(); it++)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}