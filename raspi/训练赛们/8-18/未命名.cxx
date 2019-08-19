/*
 * 未命名.cxx
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
int main(int argc, char **argv)
{
	string s;
	int x;
	cin>>x;
	int val=0;
	while(x--){
		cin>>s;
		for (int i = 0; i < 3; i++)
		{
			if(s[i]=='+'){
				val++;
				break;
			}
			if(s[i]=='-'){
				val--;
				break;
			}
		}
	}
	cout<<val<<endl;
	return 0;
}

