#include<cstdio>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
string s;
int n, m;
typedef struct aa {
	int x, y;
}pot;
char map[405][405];
queue<pot> q;
bool judge(int x, int y) {
	if (map[x][y] == 'o') {
		map[x][y] = '.';
		return true;
	}
	return false;
}
bool control(char s) {
	pot now = q.back();
	if (s == 'W') {
		if (now.x - 1 >= 0)
			q.push({
				now.x - 1, now.y
				});
		else
			return false;
		if (!judge(now.x - 1, now.y)) {
			q.pop();
		}
	}
	else if (s == 'A') {
		if (now.y - 1 >= 0)
			q.push({
				now.x, now.y - 1
				});
		else
			return false;
		if (!judge(now.x, now.y - 1)) {
			q.pop();
		}
	}
	else if (s == 'S') {
		if (now.x+1 < n)
			q.push({
				now.x+1, now.y
				});
		else
			return false;
		if (!judge(now.x + 1, now.y)) {
			q.pop();
		}
	}
	else if (s == 'D') {
		if (now.y+1 < m)
			q.push({
				now.x, now.y+ 1
				});
		else
			return false;
		if (!judge(now.x, now.y + 1)) {
			q.pop();
		}
	}
	return true;
}
int main(void) {
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '@') {
				q.push({ i,j });
				map[i][j] = '.';
			}
		}
		getchar();
	}
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (!control(s[i])) {
			printf("GG\n");
			return 0;
		}
	}
	int len1 = q.size() - 1;
	for (int i = 0; i <len1; i++) {
		pot p = q.front();
		map[p.x][p.y] = 'X';
		q.pop();
	}
	pot tt = q.front();
	map[tt.x][tt.y] = '@';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}