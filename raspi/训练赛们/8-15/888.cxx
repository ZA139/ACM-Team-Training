/*
 * 888.cxx
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

int main(int argc, char **argv)
{
	long long cnt=0;
	long long a;
	while(scanf("%lld",&a)&&a){
		if(8%a==0)
			printf("Case %lld: 1\n",++cnt);
		else if(88%a==0)
			printf("Case %lld: 2\n",++cnt);
		else if(888%a==0)
			printf("Case %lld: 3\n",++cnt);
		else if(8888%a==0)
			printf("Case %lld: 4\n",++cnt);
		else if(88888%a==0)
			printf("Case %lld: 5\n",++cnt);
		else if(888888%a==0)
			printf("Case %lld: 6\n",++cnt);
		else if(8888888%a==0)
			printf("Case %lld: 7\n",++cnt);
		else if(88888888%a==0)
			printf("Case %lld: 8\n",++cnt);
		else if(888888888%a==0)
			printf("Case %lld: 9\n",++cnt);
		else if(8888888888%a==0)
			printf("Case %lld: 10\n",++cnt);
		else if(88888888888%a==0)
			printf("Case %lld: 11\n",++cnt);
		else if(888888888888%a==0)
			printf("Case %lld: 12\n",++cnt);
		else if(8888888888888%a==0)
			printf("Case %lld: 13\n",++cnt);
		else if(88888888888888%a==0)
			printf("Case %lld: 14\n",++cnt);
		else if(888888888888888%a==0)
			printf("Case %lld: 15\n",++cnt);
		else if(8888888888888888%a==0)
			printf("Case %lld: 16\n",++cnt);
		else if(88888888888888888%a==0)
			printf("Case %lld: 17\n",++cnt);
		else if(888888888888888888%a==0)
			printf("Case %lld: 18\n",++cnt);
		else if(8888888888888888888%a==0)
			printf("Case %lld: 19\n",++cnt);
		else
			printf("Case %lld: 0\n",++cnt);
		}
	return 0;
}/*
		else if(88888888888888888888%a==0)
			printf("Case %lld: 20\n",++cnt);
		else if(888888888888888888888%a==0)
			printf("Case %lld: 21\n",++cnt);
		else if(8888888888888888888888%a==0)
			printf("Case %lld: 22\n",++cnt);
		else if(88888888888888888888888%a==0)
			printf("Case %lld: 23\n",++cnt);
		else if(888888888888888888888888%a==0)
			printf("Case %lld: 24\n",++cnt);
		else if(8888888888888888888888888%a==0)
			printf("Case %lld: 25\n",++cnt);
		else if(88888888888888888888888888%a==0)
			printf("Case %lld: 26\n",++cnt);
		else if(888888888888888888888888888%a==0)
			printf("Case %lld: 27\n",++cnt);*/

