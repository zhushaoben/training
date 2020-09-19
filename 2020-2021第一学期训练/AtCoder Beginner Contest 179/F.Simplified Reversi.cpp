#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<19;
struct Tree{
	int mi[maxn],L,R,w;
	void build(int l,int r,int x){
		mi[x]=w;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	}
	void pushdown(int x){
		mi[x<<1]=min(mi[x],mi[x<<1]);
		mi[x<<1|1]=min(mi[x],mi[x<<1|1]);
	}
	void modify(int l,int r,int x){
		if(L<=l&&R>=r){mi[x]=min(mi[x],w);return;}
		int mid=(l+r)>>1;pushdown(x);
		if(L<=mid)modify(l,mid,x<<1);
		if(R>mid)modify(mid+1,r,x<<1|1);
	}
	int query(int l,int r,int x){
		if(l==r)return mi[x];
		int mid=(l+r)>>1;pushdown(x);
		if(L<=mid)return query(l,mid,x<<1);
		return query(mid+1,r,x<<1|1);
	}
}t[2];
int main(){
	int n,q,op,x,w;scanf("%d%d",&n,&q),n-=2;
	t[0].w=t[1].w=n;t[0].build(1,n,1),t[1].build(1,n,1);
	long long ans=1ll*n*n;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&op,&x),op--,x--;
		t[op].L=x,w=t[op].query(1,n,1);
		if(w)ans-=w,t[op^1].L=1,t[op^1].R=w,t[op^1].w=x-1,t[op^1].modify(1,n,1);
	}
	printf("%lld",ans);
	return 0;
} 
