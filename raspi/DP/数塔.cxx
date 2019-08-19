/*
 * 数塔.cxx
 * 
 * Copyright 2019  <pi@raspberrypi>
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
using namespace std;
long long tower[105][105];
int main(int argc, char **argv)
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		memset(tower,0,sizeof(tower));
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <=i ; j++)
			{
				scanf("%lld",&tower[i][j]);
			}
		}
		for (int i = n; i >1 ; i--)
		{
			for (int j = 1; j<i ; j++)
			{
				tower[i-1][j]+=max(tower[i][j],tower[i][j+1]);
			}
		}
		printf("%lld\n",tower[1][1]);
	}
	return 0;1
}

