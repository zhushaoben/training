#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int a[maxn+5],b[maxn*10+5],si,fi[maxn+5],mi[maxn*4],lazy[maxn*4];
void update(int x){
	mi[x]=min(mi[x<<1],mi[x<<1|1]);
}
void build(int l,int r,int x){
	if(l==r){mi[x]=a[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	update(x);
}
void pushdown(int x){
	if(lazy[x]){
		mi[x<<1]+=lazy[x],mi[x<<1|1]+=lazy[x],
		lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],lazy[x]=0;
	}
}
int L,w1;
void change(int l,int r,int x){
	if(l>=L){mi[x]+=w1,lazy[x]+=w1;return;}
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)change(l,mid,x<<1);
	change(mid+1,r,x<<1|1);
	update(x);
}
int main(){
	int n,m,q,x,y,z,w=0;scanf("%d%d%d%d",&n,&m,&q,&x);
	for(int i=1;i<n;i++)scanf("%d",&y),w+=(y<x);
	for(int i=1;i<=m;i++){
		scanf("%d",&y);a[i]=w-=y;fi[i]=si;
		for(int i=0;i<y;i++)scanf("%d",b+(++si)),w+=(b[si]<x);
	}
	build(1,m,1);
	int ans=(mi[1]>=0);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&L,&y,&z);
		if(L<m&&((b[fi[L]+y]>x)^(z>x))){
			b[fi[L]+y]=z;
			w1=(z>x)?-1:1,L++,change(1,m,1);
			ans=mi[1]>=0;
			printf("%d\n",ans);
		}
		else printf("%d\n",ans);
	}
	return 0;
}
