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
#include <vector>
#include <cstdio>
#include <string>
#include <cctype>
#include <sstream>
#include <set>
using namespace std;
set<string> dic;
string s,buff;
int main(int argc, char **argv)
{
	while(cin>>s){
		for (int i = 0; i < s.size(); i++)
		{
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);
			else
				s[i]=' ';
		}
		stringstream ss(s);
		while(ss>>buff)
		{
			dic.insert(buff);
		}
	}
		for(set<string>::iterator it=dic.begin();it!=dic.end();it++)
		{
			cout<<*it<<endl;
		}
		return 0;
}

