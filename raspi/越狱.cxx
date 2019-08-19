/*
 * 越狱.cxx
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
#define mod 100003
using namespace std;
long long pow(long long a,long long b){
	long long ans=1;
	a%=mod;
	while(b){
		if(b&1){
			ans*=a;
			ans=ans%mod;
		}
		a*=a;
		a=a%mod;
		b=b>>1;
	}
	return ans%mod;
}
int main(int argc, char **argv)
{
	long long a,b;
	cin>>a>>b;
	long long ans=pow(a,b)-(pow(a-1,b-1)*a)%mod+mod;
	cout<<ans%mod<<endl;
	return 0;
}
