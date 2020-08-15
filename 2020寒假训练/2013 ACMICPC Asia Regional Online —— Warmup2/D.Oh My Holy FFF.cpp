#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
const LL inf=1e18;
struct Node{
	int h,id;
	bool operator < (const Node &b)const{
		if(h!=b.h)return h<b.h;
		return id>b.id;
	}
}a[N];
int L,R;
LL f[N],ma[N*3],w;
void change(int x,int l,int r){
	if(l==r){ma[x]=w;return;}
	int mid=(l+r)>>1;
	if(L<=mid)change(x<<1,l,mid);
	else change(x<<1|1,mid+1,r);
	ma[x]=max(ma[x<<1|1],ma[x<<1]);
}
LL query(int x,int l,int r){
	if(L<=l&&R>=r)return ma[x];
	int mid=(l+r)>>1;LL ans=-inf;
	if(L<=mid)ans=query(x<<1,l,mid);
	if(R>mid)ans=max(ans,query(x<<1|1,mid+1,r));
	return ans;
}
void work(){
    int n,l;scanf("%d%d",&n,&l);
    for(int i=0;i<n;i++)scanf("%d",&a[i].h),a[i].id=i+2,f[N]=1e18;
    a[n].h=0,a[n].id=1;sort(a,a+(++n));
    memset(ma,-0x3f,sizeof(LL)*min(N*3,n*4));
    L=0,w=0,change(1,1,n);
    for(int i=1;i<n;i++){
        L=max(1,a[i].id-l),R=a[i].id-1;
        f[a[i].id]=1ll*a[i].h*a[i].h+query(1,1,n);
        L=a[i].id,w=f[a[i].id]-a[i].h,change(1,1,n);
    }
    if(f[n]>0)printf("%lld\n",f[n]);
    else puts("No solution");
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
