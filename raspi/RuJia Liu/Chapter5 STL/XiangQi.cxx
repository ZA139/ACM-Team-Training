/*
 * XiangQi.cxx
 * 
 * Copyright 2019  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <cstdio>
int step_h[8][2]={{-1,-2},{1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1}};
int step_j[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int line[11][10],location;
int black_x,black_y;
bool ans=true;
typedef struct chess{
	int x,y;
	char type;
}chess;
chess map[10];
int front(int x,int y){
	int i = black_y+1;
	if(black_y==3)
		i--;
	for (; i <y ; i++)
	{
		if(line[x][i]==2)
		{
			ans++;
			location=i;
		}
	}
	return ans;
}
bool stall(int x,int y,int t){
	int nowx=x+step_j[t][0];
	int nowy=y+step_j[t][1];
	if(line[nowx][nowy]==1)
		return false;
	else
		return true;
}
void control(int x,int y,char type){
	if(type=='G'){
		if(front(x,y)==0){
			if(x==black_x){
				ans=false;
				return;
				}
				for (int i =1; i <y ; i++)
				{
					line[x][i]=1;
				}
			}
	}
	if(type=='C'){
		if(front(x,y)==1)
		for (int i =location+1; i <y ; i++)
			{
				line[x][i]=1;
			}
	}
	if(type=='H'){
		for (int i = 1; i <=8 ; i++)
		{
			if(stall(x,y,(i-1)/2))
			{
				int nowx=x+step_h[i][0];
				int nowy=y+step_h[i][1];
				line[nowx][nowy]=1;
			}
		}
	}
	return;
}
void black_G(){
	for (int i = 0; i < 4; i++)
	{
		int nowx=black_x+step_j[i][0];
		int nowy=black_y+step_j[i][1];
		if(nowx>3&&nowx<7&&nowy>0&&nowy<4&&line[nowx][nowy]!=1)
		{
			ans=false;
		}
	}
	return;
}
int main(int argc, char **argv)
{
	int t;
	while(~scanf("%d%d%d",&t,&black_x,&black_y)&&t&&black_x&&black_y){
		for (int i = 0; i < t; i++)
		{
			scanf("%c%d%d",&map[i].type,&map[i].x,&map[i].y);
			line[map[i].x][map[i].y]=2;
		}
		for (int i = 0; i < t; i++)
		{
			control(map[i].x,map[i].y,map[i].type);
		}
		black_G();
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

