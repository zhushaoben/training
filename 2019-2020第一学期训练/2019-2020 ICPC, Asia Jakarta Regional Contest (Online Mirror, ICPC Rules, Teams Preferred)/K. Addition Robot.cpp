#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
#define mo 1000000007
#define LL long long
char s[maxn+5];
struct Node{
	LL aa,ab,ba,bb;bool inv;
}a[maxn*4],ans;
int L,R;
void update(Node &a,Node b,Node c){
	a.aa=(c.aa*b.aa+c.ab*b.ba)%mo;
	a.ab=(c.aa*b.ab+c.ab*b.bb)%mo;
	a.ba=(c.ba*b.aa+c.bb*b.ba)%mo;
	a.bb=(c.ba*b.ab+c.bb*b.bb)%mo;
}
void build(int l,int r,int x){
	if(l==r){
		if(s[l]=='A')a[x]={1,1,0,1,0};
		else a[x]={1,0,1,1,0};
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	update(a[x],a[x<<1],a[x<<1|1]);
}
inline void Inv(int x){
	swap(a[x].aa,a[x].bb),swap(a[x].ab,a[x].ba);a[x].inv^=1;
}
void pushdown(int x){
	if(a[x].inv)Inv(x<<1),Inv(x<<1|1),a[x].inv=0;
}
void change(int l,int r,int x){
	if(l>=L&&r<=R){Inv(x);return;}
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)change(l,mid,x<<1);
	if(R>mid)change(mid+1,r,x<<1|1);
	update(a[x],a[x<<1],a[x<<1|1]);
}
void query(int l,int r,int x){
	if(l>=L&&r<=R){update(ans,ans,a[x]);return;}
	int mid=(l+r)>>1;pushdown(x);
	if(L<=mid)query(l,mid,x<<1);
	if(R>mid)query(mid+1,r,x<<1|1);
}
int main(){
	int n,q,op,a,b;scanf("%d%d%s",&n,&q,s+1);
	build(1,n,1);
	for(int i=0;i<q;i++){
		scanf("%d",&op);
		if(op&1){
			scanf("%d%d",&L,&R);
			change(1,n,1);
		}
		else{
			scanf("%d%d%d%d",&L,&R,&a,&b);
			ans={1,0,0,1,0},query(1,n,1);
			printf("%lld %lld\n",(a*ans.aa+b*ans.ab)%mo,(a*ans.ba+b*ans.bb)%mo);
		}
	}
	return 0;
}
