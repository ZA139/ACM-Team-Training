#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include<stdio.h>
using namespace std;

int plane[4][4] = { 0 };
int state[4][4] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int B_start_pos = 7;
int G_start_pos = 20;
int R_start_pos = 33;
int Y_start_pos = 46;
bool win = false;
int turn = 1; //0 for B;1 for G;2 for R;3 for Y;
string color[4] = { "Blue", "Green", "Red", "Yellow" };
int ran[1000] = { 0 };
int cj = 0;

int Roll()
{
	int i;
	i = rand() % 6 + 1;
	//i=ran[cj];cj++;

	cout << "You threw a " << i << endl;
	return i;
}

int Move(int i) //relative position convert
{
	if (i >= 50)
		return i;
	else if (i == 18 && i == 14)
		return i + 16;
	else if (i % 4 == 2)
		return i + 4;
	else
		return i;
}
void Action(int r, int t)
{
	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		if (state[t][i] == 0 || plane[t][i] == 0)
			continue;
		if (Move(plane[t][i] + r) >= 56)
		{
			plane[t][i] = 0;
			state[t][i] = 0;
			cout << "Plane " << color[t] << " " << i + 1 << " reached the destination." << endl;
			return;
		}
	}
	for (i = 0; i < 4; i++) //number of plane
	{
		if (state[t][i] == 0 || plane[t][i] == 0)
			continue;
		for (j = 1; j < 4; j++)     //number of other player
			for (k = 0; k < 4; k++) //number of other player's plane
				if (Move(plane[t][i] + 6 + t * 13) == plane[(t + j) % 4][k] + 6 + ((t + j) % 4) * 13)
				{
					plane[t][i] = Move(plane[t][i] + r);
					cout << "Plane " << color[t] << " " << i + 1 << " moved." << endl;
					plane[(t + j) % 4][k] = 0;
					cout << "Plane " << color[(t + j) % 4] << " " << k + 1 << " crashed." << endl;
					return;
				}
	}
	for (i = 0; i < 4; i++)
	{
		if (state[t][i] == 0 || plane[t][i] == 0)
			continue;
		if (Move(plane[t][i] + r) >= 50 && plane[t][i] <= 50)
		{
			plane[t][i] = Move(plane[t][i] + r);
			cout << "Plane " << color[t] << " " << i + 1 << " moved." << endl;
			return;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (state[t][i] == 0 || plane[t][i] == 0)
			continue;
		if (Move(plane[t][i] + r) - plane[t][i] == 16)
		{
			plane[t][i] = Move(plane[t][i] + r);
			cout << "Plane " << color[t] << " " << i + 1 << " moved." << endl;
			return;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (state[t][i] == 0 || plane[t][i] == 0)
			continue;
		if (Move(plane[t][i] + r) - plane[t][i] == 4)
		{
			plane[t][i] = Move(plane[t][i] + r);
			cout << "Plane " << color[t] << " " << i + 1 << " moved." << endl;
			return;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (state[t][i] == 0 || plane[t][i] == 0)
			continue;
		if (plane[t][i])
		{
			plane[t][i] = Move(plane[t][i] + r);
			cout << "Plane " << color[t] << " " << i + 1 << " moved." << endl;
			return;
		}
	}
}

int main()
{
	/*
	int j=0;
	freopen("cin.txt","r",stdin);
	while(1){
		scanf("%d",&ran[j]);
		if(ran[j]==0)
			break;
		j++;
	}
	*/
	freopen("txt.txt", "w", stdout);
	bool plane_ready[4];
	memset(plane_ready, true, sizeof(plane_ready));
	srand((int)time(0));
	int i, target; //target:which plane to move
	while ((!win) && turn < 10000)
	{
		int t = turn % 4;
		cout << "turns: " << turn << "    it's " << color[t] << "'s turn" << endl;
		int r = Roll();
		while (r == 6)
		{
			plane_ready[t] = plane[t][0] + state[t][0] == 1 || plane[t][1] + state[t][1] == 1 || plane[t][2] + state[t][2] == 1 || plane[t][3] + state[t][3] == 1;
			if (plane_ready[t])
				for (i = 0; i < 4; i++)
				{
					if (state[t][i] == 0 || plane[t][i] != 0)
						continue;
					if (plane[t][i] == 0)
					{
						plane[t][i] = 1; //take off now relative position is 1;
						cout << "Plane " << color[t] << " " << i + 1 << " has taken off." << endl;
						break;
					}
					//plane_ready[t] = false;
				}
			else
				Action(r, t);
			r = Roll();
		}
		if (plane[t][0] != 0 || plane[t][1] != 0 || plane[t][2] != 0 || plane[t][3] != 0)
			Action(r, t);

		for (i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << plane[i][j] << " ";
			cout << "       ";
			for (int j = 0; j < 4; j++)
				if (plane[i][j] == 0)
				{
					if (state[i][j] == 1)
						cout << "0 ";
					else
						cout << "* ";
				}
				else
					cout << plane[i][j] + 6 + 13 * i << " ";
			cout << endl;
		}
		cout << "--------------------" << endl;
		turn++;
		if (state[t][0] + state[t][1] + state[t][2] + state[t][3] == 0)
		{
			win = true;
			cout << color[t] << " wins";
		}
	}
	system("pause");
	return 0;
}