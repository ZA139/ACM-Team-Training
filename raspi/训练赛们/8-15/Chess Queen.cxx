/*
 * Chess Queen.cxx
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


#include<cstdio>
#include<algorithm>
int main(int argc, char **argv)
{
	long long n,m,a;
	while (scanf("%lld%lld",&n,&m)&&n&&m)
	{
		if(n>m)	
			std::swap(n,m);
		a=n*m*(m+n-2)+((n-1)*n*2*(3*m-n-1))/3;
		printf("%lld\n",a);
	}
	return 0;
}

