/*
 * The SetStack Computer .cxx
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
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <stack>
#define ALL(x) x.begin(),x.end()
#define INS(x) std::inserter(x,x.begin())
using namespace std;
typedef set<int>Set;
map<Set,int> ID;
vector <Set> cache;
int getID(Set s){
	if(ID.count(s))
		return ID[s];
	cache.push_back(s);
	return ID[s]=cache.size()-1;
}
int main(int argc, char **argv)
{
	int t;
	cin>>t;
	while(t--){
		stack<int> s;
		int n;
		cin>>n;
		while (n--)
		{
			string op;
			cin>>op;
			if(op[0]=='P')
				s.push(getID(Set()));
			else if(op[0]=='D')
				s.push(s.top());
			else{
				Set x=cache[s.top()];
				s.pop();
				Set y=cache[s.top()];
				s.pop();
				Set z;
				if(op[0]=='U')
					set_union(ALL(x),ALL(y),INS(z));
				if(op[0]=='I')
					set_intersection(ALL(x),ALL(y),INS(z));
				if(op[0]=='A'){
					z=y;
					z.insert(getID(x));
				}
				s.push(getID(z));
			}
		cout<<cache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
	return 0;
}

