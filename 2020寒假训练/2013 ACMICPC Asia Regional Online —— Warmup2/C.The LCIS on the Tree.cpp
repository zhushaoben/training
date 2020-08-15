#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Node{
	int l,r,sl,sr,ma,si;
}a[maxn*3],b[maxn*3];
int n,st;
int nex[maxn],V[maxn],fi[maxn],depth[maxn],size[maxn],top[maxn],son[maxn],p[maxn],fp[maxn],fa[maxn];
inline void add_edge(int u,int v){nex[v]=fi[u],fi[u]=v;}
void merge(Node &a,Node b,Node c){
	if(!b.si){a=c;return;}
	if(!c.si){a=b;return;}
	a.ma=max(b.ma,c.ma),a.l=b.l,a.r=c.r,a.sl=b.sl,a.sr=c.sr,a.si=b.si+c.si;
	if(b.r<c.l){
		a.ma=max(a.ma,b.sr+c.sl);
		if(b.si==b.ma)a.sl=b.ma+c.sl;
		if(c.si==c.ma)a.sr=c.ma+b.sr;
	}
}
void dfs1(int x){
	size[x]=1;
	for(int v=fi[x];v;v=nex[v]){
		fa[v]=x,depth[v]=depth[x]+1,dfs1(v);
		size[x]+=size[v];
		if(size[v]>size[son[x]])son[x]=v;
	}
}
void dfs2(int x,int sp){
	top[x]=sp,p[x]=++st,fp[st]=x;
	if(!son[x])return;
	dfs2(son[x],sp);
	for(int v=fi[x];v;v=nex[v]){
		if(v==son[x])continue;
		dfs2(v,v);
	} 
}
void build(int x,int l,int r){
	if(l==r){
		b[x]={V[fp[n-l+1]],V[fp[n-l+1]],1,1,1,1},a[x]={V[fp[l]],V[fp[l]],1,1,1,1};
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	merge(a[x],a[x<<1],a[x<<1|1]),merge(b[x],b[x<<1],b[x<<1|1]);
}
int L,R;
Node ansa,ansb;
void query_tb(int x,int l,int r){
	if(L<=l&&R>=r){merge(ansb,ansb,b[x]);return;}
	int mid=(l+r)>>1;
	if(L<=mid)query_tb(x<<1,l,mid);
	if(R>mid)query_tb(x<<1|1,mid+1,r);
}
void query_ta(int x,int l,int r){
	if(L<=l&&R>=r){merge(ansa,a[x],ansa);return;}
	int mid=(l+r)>>1;
	if(R>mid)query_ta(x<<1|1,mid+1,r);
	if(L<=mid)query_ta(x<<1,l,mid);
}
int query(int u,int v){
	ansa.si=ansb.si=0;
	while(top[u]!=top[v]){
		if(depth[top[u]]>depth[top[v]]){
			L=n-p[u]+1,R=n-p[top[u]]+1,query_tb(1,1,n);
			u=fa[top[u]];
		}
		else{
			L=p[top[v]],R=p[v],query_ta(1,1,n);
			v=fa[top[v]];
		}
	}
	if(depth[u]>depth[v])L=n-p[u]+1,R=n-p[v]+1,query_tb(1,1,n);
	else L=p[u],R=p[v],query_ta(1,1,n);
	merge(ansa,ansb,ansa);
	return ansa.ma;
}
void work(){
	int q,u,v;scanf("%d",&n);
	memset(fi,0,sizeof(int)*(n+5)),memset(son,0,sizeof(int)*(n+5)),st=0;
	for(int i=1;i<=n;i++)scanf("%d",V+i);
	for(int i=2;i<=n;i++)scanf("%d",&u),add_edge(u,i);
	dfs1(1),dfs2(1,1);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",query(u,v));
	}
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		work();
		if(i!=t)puts("");
	}
	return 0;
} 
