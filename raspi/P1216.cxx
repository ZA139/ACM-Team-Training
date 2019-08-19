/*
 * P1216.cxx
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
#include <cstring>
#include <algorithm>
long long map[1005][1005];
int main(int argc, char **argv)
{
	memset(map,0,sizeof(map));
	int t;
	scanf("%d",&t);
	for (int i = 1; i <=t; i++)
	{
		for (int j=1; j <=i ; j++)
		{
			scanf("%lld",&map[i][j]);
		}
	}
	for (int i = t; i >1 ; i--)
	{
		for (int j = 1; j <i ; j++)
		{
				map[i-1][j]+=std::max(map[i][j],map[i][j+1]);
		}
	}
	printf("%lld\n",map[1][1]);
	return 0;
}

