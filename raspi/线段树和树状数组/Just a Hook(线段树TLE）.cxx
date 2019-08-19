/*
1
10
2
1 5 2
5 9 3
 */


#include <iostream>
#include <cstring>
#include <cstdio>
struct ass{
	int l,r,sum,lazy=0;
}node[100000<<4];
void push_down(int x,int num){
	if(node[x].lazy){
		node[x<<1].sum=node[x].lazy;
		node[x<<1|1].sum=node[x].lazy*num/2;
		node[x<<1].lazy=node[x].lazy;
		node[x<<1|1].lazy=node[x].lazy;
		node[x].lazy=0;
	}
	return;
}
void build(int x,int l,int r){
	node[x].l=l;
	node[x].r=r;
	if(l==r){
		node[x].sum=1;
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	node[x].sum=node[x<<1].sum+node[x<<1|1].sum;
}
void update(int x,int l,int r,int val){
	int L=node[x].l,R=node[x].r;
	if(L==R){
		node[x].sum=val*(R-L+1);
		node[x].lazy=val;
		return;
	}
	//push_down(x,R-L+1);
	int mid=L+R>>1;
	if(l<=mid)
		update(x<<1,l,r,val);
	if(mid<r)
		update(x<<1|1,l,r,val);
	node[x].sum=node[x<<1].sum+node[x<<1|1].sum;
}
long long que(int x,int l,int r){
	long long ans=0;
	int L=node[x].l,R=node[x].r;
	if(l<=L&&r>=R)
		return node[x].sum;
	push_down(x,R-L+1);
	int mid=L+R>>1;                    
	if(l<=mid)
		ans+=que(x<<1,l,r);
	if(mid<r)
		ans+=que(x<<1|1,l,r);
	return ans;
}
int main(int argc, char **argv)
{
	int T,q,cnt=0;
	scanf("%d",&T);
	while(T--){
		int t,x,y,val;
		scanf("%d",&t);
		build(1,1,t);
		scanf("%d",&q);
		for (int i = 0; i <q; i++)
		{
			scanf("%d%d%d",&x,&y,&val);
			update(1,x,y,val);
		}
		printf("Case %d: The total value of the hook is %d.\n",++cnt,node[1].sum);
	}
	return 0;
}

