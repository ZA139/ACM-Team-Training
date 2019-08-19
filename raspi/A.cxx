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
#include <algorithm>
using namespace std;
typedef struct node{
	long long val;
	long long  n;
}ass;
ass a[200005],b[200005];
long long ans[200005];
bool cmp(ass c,ass d){
	return c.val<d.val;
}
int main(int argc, char **argv)
{
	memset(ans,0,sizeof(ans));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld",&a[i].val);
		a[i].n=i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%lld",&b[i].val);
		b[i].n=i;
	}
	sort(a,a+m,cmp);
	sort(b,b+m,cmp);
	for (int i = 0; i < m; i++)
	{
		std::cout<<"a\n"<<i<<":"<<a[i].val<<std::endl;
	}
	
	for (int i = 0; i < m; i++)
	{
		ans[b[i].n]=m-i-1;
	}
	for (int i = 0; i <m-1; i++)
	{
		printf("%lld ",a[ans[i]].val);
	}
	for (int i = 0; i < m; i++)
	{
		std::cout<<"ans\n"<<i<<":"<<ans[i]<<std::endl;
	}
	
	//printf("%lld\n",a[ans[m-1]].val);
	return 0;
}

