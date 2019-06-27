#include<iostream>
#include<string.h>
using namespace std;
int chess[25][25];
long long hx, hy, mx, my, cnt = 0;
int horse_control[8][2] = {
	{-2,-1},{-2,1},{-1,2},{-1,-2},{2,-1},{2,1},{1,2},{1,-2}
};
int step[2][2] = {
	{1,0},{0,1}
};
void dfs(int x, int y) {
	if (x == mx && y == my)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		int temp_X = x + step[i][0];
		int temp_Y = y + step[i][1];
		if (!chess[temp_X][temp_Y]&&temp_X<=mx&&temp_Y<=my)
		{
			dfs(temp_X, temp_Y);
		}
	}
	return;
}


void judge(int i)
{
	int temp_X = hx + horse_control[i][0];
	int temp_Y = hy + horse_control[i][1];
	if (temp_X < 0 || temp_X>20 || temp_Y < 0 || temp_Y>20)
	{
		return;
	}
	else
	{
		chess[temp_X][temp_Y] = 1;
		return;
	}
}
void horse()
{
	for (int i = 0; i < 8; i++)
	{
		judge(i);
	}
}
int main(void)
{
	memset(chess, 0, sizeof(chess));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> mx >> my >> hx >> hy;
	chess[hx][hy] = 1;
	horse();
	dfs(0, 0);
	cout << cnt << endl;
	return 0;
}