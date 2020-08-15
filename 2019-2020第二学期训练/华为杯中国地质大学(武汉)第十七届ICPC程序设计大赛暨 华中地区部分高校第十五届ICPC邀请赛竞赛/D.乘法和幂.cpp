#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5,Mo=1e7+19,mod=Mo-1;
LL ans[N*4],lazy1[N*4],lazy2[N*4];
int num[Mo+1],pow6[Mo+1],w;
void update(int x){ans[x]=(ans[x<<1]+ans[x<<1|1])%mod;}
void change(int x,LL w1,LL w2,int s){
	lazy1[x]=(lazy1[x]*w2+w1)%mod;
	(lazy2[x]*=w2)%=mod;
	ans[x]=(ans[x]*w2+w1*s)%mod;
}
void pushdown(int x,int s1,int s2){
	change(x<<1,lazy1[x],lazy2[x],s1);
	change(x<<1|1,lazy1[x],lazy2[x],s2);
	lazy1[x]=0,lazy2[x]=1;
} 
void build(int l,int r,int x){
	lazy1[x]=0,lazy2[x]=1;
	if(l==r){scanf("%d",&w),ans[x]=num[w];return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	update(x);
}
int L,R,k,k1;
void modify(int l,int r,int x){
	if(L<=l&&R>=r){change(x,k,k1,r-l+1);return;}
	int mid=(l+r)>>1;pushdown(x,mid-l+1,r-mid);
	if(L<=mid)modify(l,mid,x<<1);
	if(R>mid)modify(mid+1,r,x<<1|1);
	update(x);
}
int query(int l,int r,int x){
	if(L<=l&&R>=r)return ans[x];
	int mid=(l+r)>>1,ans1=0;pushdown(x,mid-l+1,r-mid);
	if(L<=mid)ans1+=query(l,mid,x<<1);
	if(R>mid)ans1+=query(mid+1,r,x<<1|1);
	return ans1%mod;
}
void work(){
	int n,m,op;scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&op);
		if(op==3){
			scanf("%d%d",&L,&R);
			printf("%d\n",pow6[query(1,n,1)]);
			continue;
		}
		scanf("%d%d%d",&L,&R,&k1);
		if(op==1)k=0,modify(1,n,1);
		else k=num[k1],k1=1,modify(1,n,1);
	}
}
int main(){
	int w=1,t;
	for(int i=0;i<mod;i++)num[w]=i,pow6[i]=w,w=((w<<2)+(w<<1))%Mo;
	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
