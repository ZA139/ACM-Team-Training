/*
 * A.cxx
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
int a[105],b[105],f[500];
int main(int argc, char **argv)
{
	int n,m;
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		f[a[i]]=1;
	}
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d",&b[i]);
		f[b[i]]=1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(!f[a[i]+b[j]]){
				printf("%d %d",a[i],b[j]);
				return 0;
			}
		}
		
	}
	return 0;
}

