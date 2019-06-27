#include<iostream>
#include<string.h>
using namespace std;
int chess[6][6];
int step[4][2] = {
	{1,0},{0,1},{-1,0},{0,-1}
};
long long sizex, sizey, sx, sy, tx, ty, x, y, t, cnt=0;
void dfs(int x, int y) {
	if (x == tx && y == ty)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int temp_x = x + step[i][0];
		int temp_y = y + step[i][1];
		if (!chess[temp_x][temp_y] && temp_x > 0 && temp_x <= sizex && temp_y > 0 && temp_y <= sizey)
		{
			chess[temp_x][temp_y] = 1;
			dfs(temp_x, temp_y);
			chess[temp_x][temp_y] = 0;
		}
	}
	return;
}
int main(void) {
	memset(chess, 0, sizeof(chess));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> sizex >> sizey >> t;
	cin >> sx >> sy >> tx >> ty;
	chess[sx][sy] = 1;
	while (t--)
	{
		cin >> x >> y;
		chess[x][y] = 1;
	}
	dfs(sx, sy);
	cout << cnt << endl;

	return 0;
}