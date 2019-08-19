/*
 * 完美平方数.cxx
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
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int arr[305],temp[305];
int t;
bool judge(){
	for (int i = 0; i < t; i++)
	{
		if(arr[i]!=temp[i])
			return false;
	}
	return true;
}
int main(int argc, char **argv)
{
	int res=0;
	memset(arr,0,sizeof(arr));
	memset(temp,0,sizeof(temp));
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d",&arr[i]);
		temp[i]=arr[i];
	}
	do{
		bool ans=true;
		for (int i = 0; i <t-1; i++)
		{
			float a=sqrtf(arr[i]*arr[i+1]);
			int b=(int)a;
			if(a-static_cast<float>(b)!=0.0)
				{
					printf("%f    %d\n",a,b);
					ans=false;
					break;
				}
		}
		next_permutation(arr,arr+t);
		if(ans)
			res++;
		res%=1000000007;
	}while(!judge());
	printf("%d\n",res);
	return 0;
}

