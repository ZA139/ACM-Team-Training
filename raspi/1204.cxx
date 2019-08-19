/*
 * 1204.cxx
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
3
56

7 1 1 7 7 7 7 1 1 7 1 1 1 7 1 7 7 7 7 7 1 1 1 1 7 7 7 1 1 7 7 7 7 7 7 7 1 7 1 7 7 1 1 1 1 7 1 7 7 7 7 1 7 7 7 7 7 1 1 1 1 1 7 1 1 7 1 7 1 7 7 7 7 7 1 1 1 1 7 1 1 7 1 7 1 1 7 7 7 1 1 1 1 7 1 1 7 1 1 1 1 7 1 7 1 7 7 7 1 7 7 1 1 7 7 7 7 1 1 1 1 1 7 7 1 7 1 1 7 1 7 1 7 1 1 1 1 7 1 7 1 1 7 1 1 1 7 1 1 1 7 7 1 1 7 1 7 7 1 7 7 7 1 1 7 1 1 7 1 1 1 7 7 7 1 1 7 7 1 1 1 1 1 7 7 7 7 7 7 7 1 1 7 7 7 7 1 1 1 7 7 1 7 1 7 1 7 1 7 1 1 7 7 1 1 1 7 1 7 7 7 1 1 7

 */


#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
set<int>s;
int que[10001],sticks[505],area,cn;
int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	while(t--){
		bool ans=false;
		memset(que,0,sizeof(que));
		s.clear();
		memset(sticks,0,sizeof(sticks));
		int a;
		scanf("%d",&a);
		for (int i = 0; i < a*4; i++)
		{
			int b;
			scanf("%d",&b);
			que[b]++;
			s.insert(b);
		}
		int cnt=0;
		for(set<int>::iterator it=s.begin();it!=s.end();it++){
			while(que[*it]!=0)
			{
				if(que[*it]%2==0){
				sticks[cnt++]=*it;
				que[*it]-=2;
			}
			else{
				ans=false;
				goto x;
			}
		}
		}
		cn=0;
		area=sticks[0]*sticks[cnt-1];
		for (int i = 0; i < a; i++)
		{
			if(sticks[i]*sticks[cnt-1-i]==area)
				{
					cn++;
				}
		}
		if(cn==a)
			ans=true;
		x:
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

