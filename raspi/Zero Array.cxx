/*
 * Zero Array.cxx
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

/*
#include <iostream>
#include <cstring>
#include <algorithm>
long long a[100005];
int main(int argc, char **argv)
{
	bool ans=true;
	memset(a,0,sizeof(a));
	int b=0;
	scanf("%d",&b);
	for (int i = 0; i < b; i++)
	{
		scanf("%lld",&a[i]);
	}
	std::sort(a,a+b);
	int cnt=0;
	long long temp=a[0];
	for (int i = 0; i <b ; i++)
	{
		if(a[i]==temp)
			cnt++;
		else{
			if(cnt%2!=0){
				ans=false;
				break;
			}
			cnt=1;
			temp=a[i];
		}		
	}
	if(ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}*/
#include<algorithm>
#include<iostream>
using namespace std;
int main(void){
	int a;
	ios::sync_with_stdio(false);
	cin>>a;
	long long maxa=0,sum=0,b;
	while(a--){
		cin>>b;
		maxa=max(maxa,b);
		sum+=b;
	}
	if(sum%2==0&&maxa<=(sum/2))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
