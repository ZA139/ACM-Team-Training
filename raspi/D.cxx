/*
 * D.cxx
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
using namespace std;
int alpha[27];
void print(){
	for (int i = 0; i < 27; i++)
	{
		printf("%d\n",alpha[i]);
	}
}
int main(int argc, char **argv)
{
	memset(alpha,0,sizeof(alpha));
	int t,n;
	int ans=0;
	scanf("%d%d",&t,&n);
	for (int i = 0; i < t; i++)
	{
		char ch=getchar();
		while(ch=='\n'||ch=='\r')
		{
			ch=getchar();
		}
		alpha[ch-'a']++;
	}
	//print();
	int i;
	for ( i = 0; i<26;i++)
	{
		if(alpha[i]>n)
			break;
	}
	if(i==26)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

