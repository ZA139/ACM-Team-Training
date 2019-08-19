/*
 * A..cxx
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
 * 7
abcabca
* 5
 * 
 */


#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
	string s,sb,sbb;
	ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	cin>>s;
	long long ans=0;
	for (i = n/2; i >0 ; i--)
	{
		sb=s.substr(0,i);
		sbb=s.substr(i,i);
		//cout<<sb<<endl<<sbb<<endl;
		//getchar();
//getchar();
		if(sb==sbb){
			ans=i;
			break;
		}
	}
	//cout<<"i"<<i<<endl;
	ans+=(n-2*i);
	if(i)
		ans++;
	cout<<ans<<endl;
	return 0;
}

