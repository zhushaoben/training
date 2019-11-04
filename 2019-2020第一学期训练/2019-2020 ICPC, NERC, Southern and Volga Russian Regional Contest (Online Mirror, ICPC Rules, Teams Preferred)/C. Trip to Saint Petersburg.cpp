#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=200000;
struct Node{
	int l,r,id;LL p;
	bool operator < (const Node &b)const{
		return l<b.l;
	}
}a[maxn+5];
LL b[maxn+5],ma[maxn*4],lazy[maxn*4];int ma1[maxn*4];
void update(int x){
	if(ma[x<<1]>ma[x<<1|1])ma[x]=ma[x<<1],ma1[x]=ma1[x<<1];
	else ma[x]=ma[x<<1|1],ma1[x]=ma1[x<<1|1];
}
void pushdown(int x){
	if(lazy[x]){
		lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],ma[x<<1]+=lazy[x],ma[x<<1|1]+=lazy[x];
		lazy[x]=0;
	}
}
void build(int l,int r,int x){
	if(l==r){ma[x]=b[l],ma1[x]=l;return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	update(x);
}
int L;LL w;
void modify(int l,int r,int x){
	if(L<=l){ma[x]+=w,lazy[x]+=w;return;}
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)modify(l,mid,x<<1);
	modify(mid+1,r,x<<1|1);
	update(x);
}
int main(){
//	freopen("1.in","r",stdin);
	int n,maxr=0;LL k;scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].p),a[i].id=i+1,b[a[i].r]+=a[i].p,maxr=max(maxr,a[i].r);
	for(int i=1;i<=maxr;i++)b[i]+=b[i-1]-k;
	build(1,maxr,1);sort(a,a+n);
	int l=0,ans1=1,ans2=ma1[1];LL ans=max(0ll,ma[1]);
	for(int i=1;i<maxr;i++){
		while(l<n&&a[l].l==i)L=a[l].r,w=-a[l].p,modify(1,maxr,1),l++;
		L=i+1,w=k,modify(1,maxr,1);
		if(ma[1]>ans)ans=ma[1],ans1=i+1,ans2=ma1[1];
	}
	if(ans){
		int num=0;
		for(int i=0;i<n;i++)if(ans1<=a[i].l&&ans2>=a[i].r)num++;
		printf("%lld %d %d %d\n",ans,ans1,ans2,num);
		for(int i=0;i<n;i++)if(ans1<=a[i].l&&ans2>=a[i].r)printf("%d ",a[i].id);
	}
	else puts("0");
	return 0;
}
