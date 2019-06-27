#include<iostream>
#include<string>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
string judge_leave(tm m1, tm m2, string a, string b) {
	if (m1.tm_hour > m2.tm_hour)
	{
		return a;
	}
	else if (m1.tm_hour < m2.tm_hour)
		return b;
	else
	{
		if (m1.tm_min > m2.tm_min)
			return a;
		else if (m1.tm_min < m2.tm_min)
			return b;
		else
		{
			if (m1.tm_sec > m2.tm_sec)
				return a;
			else
				return b;
		}
	}
}
string judge_arrive(tm m1, tm m2, string a, string b) {
	if (m1.tm_hour < m2.tm_hour)
	{
		return a;
	}
	else if (m1.tm_hour > m2.tm_hour)
		return b;
	else
	{
		if (m1.tm_min < m2.tm_min)
			return a;
		else if (m1.tm_min > m2.tm_min)
			return b;
		else
		{
			if (m1.tm_sec < m2.tm_sec)
				return a;
			else
				return b;
		}
	}
}
int main(void) {
	string a, ans1, ans2, b;
	typedef vector<tm> vt;
	map<string, vt>m;
	int M, N;
	cin >> M;

	while (M--)
	{
		bool first = true;
		cin >> N;
		while (N--)
		{
			m.clear();
			tm t1, t2;
			cin >> a;
			if (first)
			{
				ans1 = ans2 = a;
				first = false;
			}
			scanf("%d:%d:%d%d:%d:%d", &t1.tm_hour, &t1.tm_min, &t1.tm_sec, &t2.tm_hour, &t2.tm_min, &t2.tm_sec);
			m[a].push_back(t1);
			m[a].push_back(t2);
			ans1 = judge_arrive(m[a].at(0), m[ans1].at(0), a, ans1);
			ans2 = judge_leave(m[a].at(1), m[ans2].at(1), a, ans2);
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}