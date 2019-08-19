/*
 * 母牛的故事.cxx
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
#include <cstring>
long long cows[100];
void slove(){
	memset(cows,0,sizeof(cows));
	cows[1]=1;cows[2]=2;cows[3]=3;
	for (int i = 4; i < 60; i++)
	{
		cows[i]=cows[i-1]+cows[i-3];
	}
	return;
}
int main(int argc, char **argv)
{
	slove();
	int n;
	while(scanf("%d",&n)&&n)
	{
		printf("%lld\n",cows[n]);
	}
	return 0;
}

