/*
 * f.cxx
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
#include <algorithm>
#include <string>
using namespace std;
typedef struct ass{
	string n;
}type;
string t,s;
bool cmp(ass a,ass b){
	return a.n<b.n;
}
type rat[100],women[100],men[100],ca[100];
int main(int argc, char **argv)
{
	int t1,a,b,c,d;
	a=b=c=d=0;
	ios::sync_with_stdio(false);
	cin>>t1;
	while(t1--){
		cin>>s>>t;
		if(t[0]=='r')
			rat[a++].n=s;
		else if(t[0]=='w'||t=="child")
			women[b++].n=s;
		else if(t[0]=='m')
			men[c++].n=s;
		else if(t=="captain")
			ca[d++].n=s;
	}
	//sort(rat,rat+a,cmp);
	//sort(women,women+b,cmp);
	//sort(men,men+c,cmp);
//sort(ca,ca+d,cmp);
	for (int i = 0; i < a; i++)
	{
		cout<<rat[i].n<<endl;
	}
	for (int i = 0; i < b; i++)
	{
		cout<<women[i].n<<endl;
	}
	for (int i = 0; i < c; i++)
	{
		cout<<men[i].n<<endl;
	}
	for (int i = 0; i < d; i++)
	{
		cout<<ca[i].n<<endl;
	}
	return 0;
}

