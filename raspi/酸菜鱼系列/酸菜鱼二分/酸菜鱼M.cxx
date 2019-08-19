/*
 * Maximum Median.cxx
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
long long n,k;
long long arr[200005];
bool check(long long a){
	long long ans=0;
	for (int i = n/2; i <n ; i++)
	{
		ans+=(a-arr[i]);
	if(ans>k)
		return false;
	}
	if(ans>k)
		return false;
	else
		return true;
}
	
int main(int argc, char **argv)
{
	memset(arr,0,sizeof(arr));
	scanf("%lld%lld",&n,&k);
	for (int i = 0; i <n; i++)
	{
		scanf("%lld",&arr[i]);
	}
	std::sort(arr,arr+n);
	long long l=arr[n/2],r=100000000000000;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%lld\n",r);
	return 0;
}

