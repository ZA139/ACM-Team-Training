/*
 * H.cxx
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
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
	int m,b;
	long long ans=0;
	scanf("%d%d",&m,&b);
	for (int y= 0; y<=b/2; y++)
	{
		long long mx=m*(b-y);
		long long temp=0;
		long long  n=mx+1;
		for (long long i = 0; i <=y; i++)
		{
			temp+=(n*i+(n*(n-1))/2);
		}
		//cout<<temp<<endl;
		//getchar();
		//getchar();
		ans=max(ans,temp);
	}
	printf("%lld\n",ans);
	return 0;
}

