/*
 * ass.cxx
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
 * 5
4
1 2 3 4
3
1 3 2
5
1 2 3 5 4
1
1
5
3 2 1 5 4

 * 
 */


#include <iostream>
#include <cstring>
#include <cstdio>
int ans[205];
bool res;
int t;
bool slove(int a){
	int n;
	if(ans[a]+1==ans[a+1])
		n=1;
	else if(ans[a]+1==ans[a-1])
		n=-1;
	else
		return false;
	int cnt=1;
	for (int i = a; cnt<t ; i+=n)
	{
		if(ans[i]+1==ans[i+n])
			cnt++;
	}
	return cnt==t;
}
int main(int argc, char **argv)
{
	int a;
	scanf("%d",&a);
	while(a--){
		scanf("%d",&t);
		memset(ans,0,sizeof(ans));
		for (int i = 0; i < t; i++)
		{
			scanf("%d",&ans[i]);
			ans[i+t]=ans[i];
		}
		res=true;
		for (int i = 0; i < 2*t; i++)
		{
			if(ans[i]==1){
				if(slove(i))
					break;
				else
					continue;
				}
		}		
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

