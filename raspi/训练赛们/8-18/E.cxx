/*
 * E.cxx
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
 * 19
1
1 1
1
1 2
1
1 1000
1
1 2000
1
2 2
1
2 3
1
2 1000
1
2 2000
1
1999 1999
1
1999 2000
1
2000 2000
2
1 1
1 1
2
1 1
1 2
2
1 2
1 1
2
1 2000
1 1
2
1 1
1 2000
2
1 2000
2 2
2
2 2000
2 2
2
2 2
2 2000
 */


#include <iostream>
#include <cstring>
#include <cstdio>
int p[1005][2];
int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	while(t--){
		memset(p,0,sizeof(p));
		int n;
		scanf("%d",&n);
		for (int i = 0; i <n ; i++)
		{
			scanf("%d%d",&p[i][0],&p[i][1]);
		}
		int min=0;
		for (int i = 0; i <n ; i++)
		{
			if(p[i][1]<=min)
				printf("0 ");
			else{
				min++;
				if(min>p[i][0])
				printf("%d ",min);
				else{
				printf("%d ",p[i][0]);
				min=p[i][0];
			}
			}
		}
		printf("\n");
	}
	return 0;
}

