/*
 * 未命名.cxx
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
 * 1
10
2
1 5 2
5 9 3
 */

#include <cstdio>
#include <cstring>
int map[1000005][3];
int main(int argc, char **argv)
{
	int T,q,cnt=0,sum=0;
	scanf("%d",&T);
	while(T--){
		sum=0;
		memset(map,0,sizeof(map));
		int t;
		scanf("%d",&t);
		scanf("%d",&q);
		for (int i = 1; i <=q; i++)
		{
			scanf("%d%d%d",&map[i][0],&map[i][1],&map[i][2]);
		}
		for (int i = 1; i <=t ; i++)
		{
			int val=1;
			for (int j = q; j >=0 ; j--)
			{
				if(map[j][0]<=i&&map[j][1]>=i){
					val=map[j][2];
					break;
				}
				
			}	
			sum+=val;
		}
		printf("Case %d: The total value of the hook is %d.\n",++cnt,sum);
	}
	return 0;
}

