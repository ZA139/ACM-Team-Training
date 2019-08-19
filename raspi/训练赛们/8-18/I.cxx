/*
 * I.cxx
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
#include <set>
#include <cstring>
#include <cstdio>
using namespace std;
long long ans[30005];
set<long long>s;
int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	while(t--){
		s.clear();
		int n;
		scanf("%d",&n);
		long long a;
		for (int i = 1; i <=n; i++)
		{
			scanf("%lld",&a);
			s.insert(a);
			long long sum=0;
			for (set<long long>::iterator it=s.begin();it!=s.end();it++)
			{
				sum+=*it;
			}
			ans[i]=sum;
		}
		int q;
		scanf("%d",&q);
		while(q--){
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",ans[r]-ans[l]+1);
	}
	}	
	return 0;
}

