#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

#define MAXN 30
vector<int> v[MAXN];
int n;

void clean_above(int position, int height ) {
	for (int i = height+1; i <v[position].size(); i++)
	{
		int temp = v[position][i];
		v[temp].push_back(temp);
	}
	v[position].resize(1 + height);
	return;
}

void find_blocks(int a, int &p, int &h) {
	for ( p = 0;  p < n;  p++)
	{
		for ( h = 0; h < v[p].size(); h++)
		{
			if (v[p][h]==a)
			{
				return;
			}
		}
	}
}

void move_blocks(int p1,int h,int p2) {//p1->p2
	for (int i = h; i < v[p1].size(); i++)
	{
		v[p2].push_back(v[p1][i]);
	}
	v[p1].resize(h);
	return;
}

void print() {
	for (int i = 0; i < n; i++)
	{
		printf("%d:", i);
		for (int k = 0; k < v[i].size(); k++)
		{
			printf(" %d", v[i][k]);
		}
		printf("\n");
	}
	return;
}
int main(void) {
	//freopen("txt.txt", "r", stdin);
	int a, b;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++)
	{
		v[i].push_back(i);
	}
	while (1)
	{
		cin >> s1;
		if (s1 == "quit") break;
		cin >> a >> s2 >> b;
		int pa, pb, ha, hb;
		find_blocks(a, pa, ha);
		find_blocks(b, pb, hb);
		if (pa == pb) continue;
		if (s1 == "move")clean_above(pa, ha);
		if (s2 == "onto") clean_above(pb, hb);
		move_blocks(pa, ha, pb);
	}
	print();
	return 0;
}