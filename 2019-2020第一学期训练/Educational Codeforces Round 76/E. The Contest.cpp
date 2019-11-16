#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int a[maxn+5],b[maxn+5],lazy[maxn*4],mi[maxn*4],n;
void update(int x){mi[x]=min(mi[x<<1],mi[x<<1|1]);}
void pushdown(int x){if(lazy[x])mi[x<<1]+=lazy[x],mi[x<<1|1]+=lazy[x],lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],lazy[x]=0;}
void build(int l,int r,int x){
	if(l==r){mi[x]=n-l+1-b[l]-(a[n]-a[l-1])+b[1]-b[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	update(x);
}
int L;
void modify(int l,int r,int x){
	if(L<=l){mi[x]--,lazy[x]--;return;}
	int mid=(l+r)>>1;pushdown(x);
	if(L<=mid)modify(l,mid,x<<1);
	modify(mid+1,r,x<<1|1);
	update(x);
}
void modify1(int l,int r,int x){
	if(r<=L){mi[x]++,lazy[x]++;return;}
	int mid=(l+r)>>1;pushdown(x);
	modify1(l,mid,x<<1);
	if(L>mid)modify1(mid+1,r,x<<1|1);
	update(x);
}
int main(){
	int k1,k2,k3,x;scanf("%d%d%d",&k1,&k2,&k3),n=k1+k2+k3+1;
	for(int i=0;i<k1;i++)scanf("%d",&x),a[x]++;
	for(int i=0;i<k2;i++)scanf("%*d");
	for(int i=0;i<k3;i++)scanf("%d",&x),b[x]++;b[n]++;
	for(int i=n-1;~i;i--)b[i]+=b[i+1];
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	build(1,n,1);int ans=k1+mi[1];
	for(int i=1;i<n;i++){
		if(b[i]!=b[i-1])L=i+1,modify(1,n,1);
//		else if(a[i]!=a[i-1])L=i,modify1(1,n,1);
		ans=min(ans,i-a[i]+k1-a[i]+mi[1]);
	}
	printf("%d",ans);
	return 0;
}
