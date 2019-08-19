/*
 * G.cxx
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
long long sol[105],k[105];
int main(int argc, char **argv)
{
	long long n,m,cnt=0,t,ans=0;
	scanf("%lld%lld",&n,&m);
	for (int i = 0; i <n; i++)
	{
		scanf("%lld",&t);
		sol[t]++;
		k[t]++;
		if(t==m)
			cnt++;
	}
	while(cnt<n){
		sol[m]=0;
		for (int i = 1; i <m; i++)
		{
			if(k[i]){
				sol[i]--;
				sol[i+1]++;
			}
		}
		ans++;
		cnt+=sol[m];
		for (int i = 0; i < m; i++)
		{
			k[i]=sol[i];
		}
		
	}
	printf("%lld\n",ans);
	return 0;
}

