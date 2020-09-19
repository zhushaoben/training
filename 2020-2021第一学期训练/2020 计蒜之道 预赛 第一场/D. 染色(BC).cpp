#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e5+5;
struct Node{
	int l,r,t,c;
	bool operator < (const Node &b)const{return r<b.r;}
}a[N];
int w[N],b[N],L;
LL mi1[N<<2],mi2[N<<2],lazy1[N<<2],lazy2[N<<2],k;
void pushdown(int x,LL mi[],LL lazy[]){
	if(lazy[x]){
		lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x];
		mi[x<<1]+=lazy[x],mi[x<<1|1]+=lazy[x];
		lazy[x]=0;
	}
}
void change(int l,int r,int x,LL mi[],LL lazy[]){
	if(l==r){mi[x]+=k;return;}
	pushdown(x,mi,lazy);
	int mid=(l+r)>>1;
	if(L<=mid)change(l,mid,x<<1,mi,lazy);
	else change(mid+1,r,x<<1|1,mi,lazy);
	mi[x]=max(mi[x<<1],mi[x<<1|1]);
}
void modify(int l,int r,int x,LL mi[],LL lazy[]){
	if(r<=L){mi[x]+=k,lazy[x]+=k;return;}
	pushdown(x,mi,lazy);
	int mid=(l+r)>>1;
	modify(l,mid,x<<1,mi,lazy);
	if(L>mid)modify(mid+1,r,x<<1|1,mi,lazy);
	mi[x]=max(mi[x<<1],mi[x<<1|1]);
}
int main(){
	int n,m,l=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=0;i<m;i++)scanf("%d%d%d%d",&a[i].t,&a[i].l,&a[i].r,&a[i].c);
	sort(a,a+m);n++;
	LL ans=0,w1=0,b1=0;
	for(int i=1;i<n;i++){
		w1+=w[i],b1+=b[i];
		while(a[l].r==i){
			L=a[l].l,k=a[l].c;
			if(a[l].t==1)modify(1,n,1,mi1,lazy1);
			else modify(1,n,1,mi2,lazy2);
			l++;
		}
		ans=max(mi1[1]+b1,mi2[1]+w1);
		L=i+1,k=max(0ll,ans-b1);change(1,n,1,mi1,lazy1);
		L=i+1,k=max(0ll,ans-w1);change(1,n,1,mi2,lazy2);
	}
	printf("%lld",ans);
	return 0;
}
