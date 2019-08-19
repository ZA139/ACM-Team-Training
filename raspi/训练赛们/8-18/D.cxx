/*
 * D.cxx
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
#include <cmath>
using namespace std;
int bed[300];
int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	while(t--){
		//memset(bed,0,sizeof(bed));
		int x,y;
		scanf("%d%d",&x,&y);
		for (int i = 1; i <=y; i++)
		{
			scanf("%d",&bed[i]);
		}
		int ans=0;
		for (int i = 1; i <=x; i++)
		{
			int mi=x;
			for (int j = 1 ; j<=y; j++)
			{
				mi=min(mi,abs(i-bed[j]));
			}
			ans=max(ans,mi);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}

