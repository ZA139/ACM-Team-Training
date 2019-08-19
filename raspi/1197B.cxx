/*
 * 1197B.cxx
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
 * 4
1 3 4 2
3
3 1 2
 * 
 */


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
int pi[200005];
int main(int argc, char **argv)
{
	memset(pi,0,sizeof(pi));
	int a;
	int max=0,temp=0;
	scanf("%d",&a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d",&pi[i]);
		if(max<pi[i]){
			max=pi[i];
			temp=i;
		}
	}
	int l=temp-1,r=temp+1;
	while(l>=0&&r<a){
		int temp1;
		if(l<=0){
			temp=pi[r];
			r++;
		}
		else if(r>=a){
			temp=pi[l];
			l--;
		}
		else{
			if(pi[l]<pi[r]){
			temp1=pi[r];
			r++;
		}
		else if(pi[l]>pi[r]){
			temp1=pi[l];
			l--;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
		if(temp1<max){
			max=temp1;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}

