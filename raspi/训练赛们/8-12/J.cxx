/*
 * J.cxx
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
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
long long num[100005];
vector<int>v[100005];
bool visit[100005];
long long slove(int i){
	long long ans=num[i];
	visit[i]=true;
	for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++)
	{
		ans=min(ans,slove(*iter));
	}
	return ans;
}
int main(int argc, char **argv)
{
	memset(visit,0,sizeof(visit));
	memset(v,0,sizeof(v));
	int m,n;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld",&num[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y<x)
			swap(x,y);
		v[x-1].push_back(y-1);
	}
	long long ans=0;
	for (int i = 0; i < n; i++)
	{
		if(!visit[i])
			{
				ans+=slove(i);
			}
	}
	printf("%lld\n",ans);
	return 0;
}

