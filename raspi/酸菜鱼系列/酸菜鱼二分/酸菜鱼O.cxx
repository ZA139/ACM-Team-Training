/*
 * Sushi for Two.cxx
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
int sushi[100005],size1=1;
using namespace std;
bool check(int b){
	int cnt=0;
	for (int i = 0; i < size1; i++)
	{
		if(sushi[i]>=b)
		{
			cnt++;
			if(cnt==2)
				return true;
		}
		else
			cnt=0;
	}
	return false;
}
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int a,cnt=0,temp=0;
	cin>>a;
	for (int i = 0; i < a; i++)
	{
		int b;
		cin>>b;
		if(b!=temp){
			cnt++;
			temp=b;
			size1++;
		}
		sushi[cnt]++;
	}
	int l=0;
	int r=a/2;
	while(l<=r){
		int mid=(l+r)>>1;
	if(check(mid))
		l=mid+1;
	else
		r=mid-1;
	}
	cout<<r*2<<endl;
	return 0;
}

