#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=998244353,inf=1e9;
typedef long long LL;
struct Node{
	int x,d;
	bool operator < (const Node &b)const{
		return x>b.x;
	}
}a[N];
struct Tree{
	int mi;
	Tree *l,*r;
}*rt;
int f[N],L,R;
int query(Tree *p,int l,int r){
	if(!p)return inf;
	if(L<=l&&R>=r)return p->mi;
	int mid=(1ll*l+r)>>1,ans=inf;
	if(L<=mid)ans=min(ans,query(p->l,l,mid));
	if(R>mid)ans=min(ans,query(p->r,mid+1,r));
	return ans;
}
void change(Tree *&p,int l,int r){
	if(!p)p=new Tree{R,0,0};
	if(l==r)return;
	p->mi=min(p->mi,R);
	int mid=(1ll*l+r)>>1,ans=inf;
	if(L<=mid)change(p->l,l,mid);
	else change(p->r,mid+1,r);
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].d);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		L=a[i].x+1e9+1,R=min(1ll*a[i].x+1e9+a[i].d,1ll+2e9);
		int w=min(i,query(rt,1,2e9+1));R=w;change(rt,1,2e9+1);
		f[i]=(f[i-1]+f[w-1])%mo;
	}
	printf("%d",f[n]);
	return 0;
} 
