/*
 * 1197C.cxx
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
 */


#include <cstdio>
#include <algorithm>
using namespace std;
long long nums[300005];
int main(int argc, char **argv)
{
	int N,T;
	scanf("%d%d",&N,&T);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld",&nums[i]);
	}
	if(N<=T){
		printf("0\n");
		return 0;
	}

	for (int i =N-1; i >0; i--)
	{
		nums[i]=nums[i]-nums[i-1];
	}
	nums[0]=0;
	sort(nums,nums+N);
	long long ans=0;
	for (int i = 0; i <=N-T ; i++)
	{
		ans+=nums[i];
	}
	printf("%lld\n",ans);
	return 0;
}
