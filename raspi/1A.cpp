/*
 * 1A
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
using namespace std;
bool ans[4];
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	ans[1]=ans[2]=1;
	ans[3]=0;
	int a;
	cin>>a;
	while(a--){
		int b,temp;
		cin>>b;
		if(!ans[b]){
			cout<<"NO\n";
			return 0;
		}
		 for (int i = 1; i < 4; i++)
		 {
			 if(ans[i]==0)
				temp=i;
		 }
		 for (int i = 1; i < 4; i++)
		 {
			 if(ans[i]==1&&i!=b)
				ans[i]=0;
		 }
		 ans[temp]=1;
	 }
	cout<<"YES\n";
	return 0;
}

