/*
 * Ananagrams.cxx
 * 
 * Copyright 2019  <pi@raspberrypi>
 * 未命名
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
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
map<string,int> m;
vector<string> words;
string standard(const string& s){
	string ans=s;
	for (int i = 0; i < ans.size(); i++)
	{
		ans[i]=tolower(ans[i]);
	}
	sort(ans.begin(),ans.end());
	return ans;
}	
int main(int argc, char **argv)
{	
	set<string>s;
	string ss;
	while(cin>>ss&&ss[0]!='#'){
		words.push_back(ss);
		string a=standard(ss);
		if(!m.count(a))
			m[a]=0;
		m[a]++;
	}
	for (vector<string>:: iterator i =words.begin(); i!=words.end(); i++)
	{
		if(m[standard(*i)]==1)
			s.insert(*i);
	}
	for(set<string>:: iterator i=s.begin();i!=s.end();i++){
		cout<<*i<<endl;
	}
	return 0;
}

