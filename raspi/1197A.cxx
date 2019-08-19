/*
 * 1197A.cxx
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
#include <cstdio>
#include <algorithm>
using namespace std;
long long sticks[100005];
int main(int argc, char **argv)
{
	int a;
	scanf("%d",&a);
	while (a--)
	{
		long long t;
		scanf("%lld",&t);
		memset(sticks,0,sizeof(sticks));
		for (int i = 0; i <t ; i++)
		{
			scanf("%lld",&sticks[i]);
		}
		sort(sticks,sticks+t);
		long long ans=t-2;
		int len=min(sticks[t-1],sticks[t-2]);
		if(ans>=len)
			ans=len-1;
		printf("%lld\n",ans);
	}
	return 0;
}

