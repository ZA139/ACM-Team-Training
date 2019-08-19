/*
 * I Hate It.cxx
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
#include <cstdio>
#include <algorithm>
using namespace std;
struct ass{
    int l,r,max,val;
}stu[200005<<4];
long long a[200005];
void push_up(int x){
    stu[x].max=max(stu[x<<1].max,stu[x<<1|1].max);
    return;
}
void build(int rt,int l,int r){
    stu[rt].l=l;
    stu[rt].r=r;
    if(stu[rt].l==stu[rt].r){
        stu[rt].val=a[l];
        stu[rt].max=a[l];
        return;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void change(int rt,int p,int val){
    int l=stu[rt].l,r=stu[rt].r;
    if(stu[rt].l==stu[rt].r){
        stu[rt].max=max(stu[rt].max,val);
        stu[rt].val=val;
        return;
    }
    int mid=l+r>>1;
    if(p<=mid)
        change(rt<<1,p,val);
    else
        change(rt<<1|1,p,val);
    push_up(rt);
}
long long FindMax(int rt,int L,int R){
    int l=stu[rt].l,r=stu[rt].r;
    if(l>=L&&r<=R)
        return stu[rt].max;
    long long ans=0;
    int mid=l+r>>1;
    if(L<=mid)
        ans=max(ans,FindMax(rt<<1,L,R));
    if(mid<R)
        ans=max(ans,FindMax(rt<<1|1,L,R));
    return ans;
}
int main(int argc, char **argv)
{

    int N,M;
    char ch[2];
    int l,r;
    while(scanf("%d%d",&N,&M)!=EOF){
        for (int i = 1; i <=N; i++)
        {
            scanf("%lld",&a[i]);
        }
        build(1,1,N);
        for (int i = 0; i <M ; i++)
        {
            scanf("%s%d%d",ch,&l,&r);
            if(ch[0]=='U')
                change(1,l,r);
            else if(ch[0]=='Q')
                printf("%lld\n",FindMax(1,l,r));
        }
    }
    return 0;
}

