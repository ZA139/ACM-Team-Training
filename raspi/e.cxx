/*
 * e.cxx
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
long long sum=0;
int arr[1000005];
int main(int argc, char **argv)
{
	memset(arr,0,sizeof(arr));
	long long a;
	std::ios::sync_with_stdio(false);
	std::cin>>a;
	for (int i = 0; i < a; i++)
	{
		long long t;
		std::cin>>t;
		arr[i]=t%2;
	}
	int i;
	for ( i = 0; i < a; i++)
	{
		if(arr[i]&1)
		{
			std::cout<<"First\n";
			break;
		}
	}
	if(i==a)
		std::cout<<"Second\n";
	return 0;
}

