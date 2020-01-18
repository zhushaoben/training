#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
inline char readc(){ 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int readint(){
    char c; int r;
    while(c = readc()){if(c >= '0' && c <= '9'){r = c^0x30;break;}}
    while(isdigit(c = readc()))r = (r<<3)+(r<<1)+(c^0x30);
    return r;
}
struct Node{
	int l,r,x;
}a[maxn*200];
int c[maxn],fa[maxn],si,dep[maxn],t1[maxn],t2[maxn];
int L,R,w,now,n;
void insert1(int l,int r,int &x){
	a[++si]=a[x],x=si;a[x].x+=w;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(L<=mid)insert1(l,mid,a[x].l);
	else insert1(mid+1,r,a[x].r);
}
void insert2(int l,int r,int &x){
	a[++si]=a[x],x=si;a[x].x=w;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(L<=mid)insert2(l,mid,a[x].l);
	else insert2(mid+1,r,a[x].r);
}
int merge1(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	int w=++si;a[w].x=a[x].x+a[y].x;
	if(l==r)return w;
	int mid=(l+r)>>1;
	a[w].l=merge1(a[x].l,a[y].l,l,mid);
	a[w].r=merge1(a[x].r,a[y].r,mid+1,r);
	return w;
}
int merge2(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	int w1=++si;
	if(l==r){
		L=max(a[x].x,a[y].x),w=-1,insert1(1,n,t1[now]);
		a[w1].x=min(a[x].x,a[y].x);
		return w1;
	}
	int mid=(l+r)>>1;
	a[w1].l=merge2(a[x].l,a[y].l,l,mid);
	a[w1].r=merge2(a[x].r,a[y].r,mid+1,r);
	return w1;
}
int query(int l,int r,int x){
	if(L<=l&&R>=r)return a[x].x;
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)ans+=query(l,mid,a[x].l);
	if(R>mid)ans+=query(mid+1,r,a[x].r);
	return ans;
}
void work(){
	int m,last=0,u,d;n=readint(),m=readint();
	si=0;memset(t1,0,sizeof(t1)),memset(t2,0,sizeof(t2));
	for(int i=1;i<=n;i++)c[i]=readint();
	dep[1]=1;
	for(int i=2;i<=n;i++)fa[i]=readint(),dep[i]=dep[fa[i]]+1;
	for(int i=1;i<=n;i++){
		L=dep[i],w=1,insert1(1,n,t1[i]);
		L=c[i],w=dep[i],insert2(1,n,t2[i]);
	}
	for(int i=n;i>1;i--){
		now=fa[i],t1[fa[i]]=merge1(t1[fa[i]],t1[i],1,n);
		t2[fa[i]]=merge2(t2[fa[i]],t2[i],1,n);
	}	
	for(int i=0;i<m;i++){
		u=readint()^last,d=readint()^last;
		L=dep[u],R=dep[u]+d,last=query(1,n,t1[u]);
		printf("%d\n",last);
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
