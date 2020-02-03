#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
int p[maxn],a[maxn],fp[maxn];
LL mi[maxn*4],lazy[maxn*4],s[maxn];
inline void update(int x){mi[x]=min(mi[x<<1],mi[x<<1|1]);}
inline void pushdown(int x){if(lazy[x])lazy[x<<1]+=lazy[x],mi[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],mi[x<<1|1]+=lazy[x],lazy[x]=0;} 
void build(int l,int r,int x){
	if(l==r){mi[x]=s[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1),update(x);
}
int L,R,w;
void modify(int l,int r,int x){
	if(L>R)return;
	if(L<=l&&R>=r){mi[x]+=w,lazy[x]+=w;return;}
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)modify(l,mid,x<<1);
	if(R>mid)modify(mid+1,r,x<<1|1);
	update(x); 
}
int main(){
	int n,ans;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i),fp[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",a+i),s[i]=s[i-1]+a[i];
	ans=min(a[1],a[n]);build(1,n-1,1);
	for(int i=1;i<=n;i++){
		L=1,R=fp[i]-1,w=a[fp[i]],modify(1,n-1,1);
		L=fp[i],R=n-1,w=-a[fp[i]],modify(1,n-1,1);
		ans=min(1ll*ans,mi[1]);
	}
	printf("%d",ans);
	return 0;
}
