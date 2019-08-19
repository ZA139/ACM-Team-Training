/*
 * C.cxx
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
int main(int argc, char **argv)
{
	int x,y,t;
	ios::sync_with_stdio(false);
	cin>>x>>y>>t;
	if(x>y)
	{
		if(y+t>=x)
			{
				cout<<"?"<<endl;
				return 0;
			}
		if(y+t<x)
			{
				cout<<"+"<<endl;
				return 0;
			}
	}
	else if(x==y){
		if(!t)
			{
				cout<<"0\n";
				return 0;
			}
		else
			{
				cout<<"?"<<endl;
				return 0;
			}
	}
	else if(x<y){
		if(x+t>=y)
			{cout<<"?"<<endl;
				return 0;
			}
		else
		{
			cout<<"-"<<endl;
			return 0;
		}
	}
	return 0;
}

