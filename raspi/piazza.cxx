/*
 * piazza.cxx
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
#include <cmath>
#include <cstdio>

double cal(int x,int y){
		return sqrtf(x*x+y*y);
}
int main(int argc, char **argv)
{
	int R,r,t;
	scanf("%d%d",&R,&r);
	int ans=0;
	scanf("%d",&t);
	while(t--){
		int x,y,r1;
		scanf("%d%d%d",&x,&y,&r1);
		double dis=cal(x,y);
		if(dis+r1<=R&&dis-r1>=(R-r))
			ans++;
		}
	printf("%d\n",ans);
	return 0;
}

