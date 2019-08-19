/*
 * 1023A.cxx
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
Examples
inputCopy
6 10
code*s
codeforces
outputCopy
YES
inputCopy
6 5
vk*cup
vkcup
outputCopy
YES
inputCopy
1 1
v
k
outputCopy
NO
inputCopy
9 6
gfgf*gfgf
gfgfgf
outputCopy
NO
 */


#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string s,s1,cs,cs2,cs3,cs4;
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int n,m;
	scanf("%d%d",&n,&m);
	cin>>s;
	cin>>s1;
	int i=1;
	for (i = 0; i <n; i++)
	{
		if(s[i]=='*')
			break;
	}
	if(i==n){
		if(s==s1)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	cs=s.substr(0,i);
	cs2=s1.substr(0,i);
	if(cs!=cs2){
		printf("NO\n");
		return 0;
	}
	else{
	for (int j =n; j>i ; j--)
	{
		if(s[j]!=s1[m]||m<i){
			printf("NO\n");
			return 0;
		}
		m--;
	}
}
	printf("YES\n");
	return 0;
}

