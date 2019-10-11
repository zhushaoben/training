#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define LL long long
#define inf 2000000000
struct Node{
	int l,r,lazy2;
	LL sum,lazy1;
}a[maxn*8];
int l[maxn],r[maxn];
int L,R,w,si;
void pushdown(int x,int s1){
	if(!a[x].l)a[x].l=++si;
	if(!a[x].r)a[x].r=++si;
	a[a[x].l].lazy1+=a[x].lazy1,a[a[x].l].lazy2+=a[x].lazy2,a[a[x].l].sum+=(a[x].lazy1+a[x].lazy1+a[x].lazy2*(s1-1))*s1/2;
	a[a[x].r].lazy1+=a[x].lazy1+a[x].lazy2*s1,a[a[x].r].lazy2+=a[x].lazy2,a[a[x].r].sum=a[x].sum-a[a[x].l].sum;
	a[x].lazy1=a[x].lazy2=0;
}
void update(int x){
	a[x].sum=a[a[x].l].sum+a[a[x].r].sum;
}
void change(int &x,int l,int r){
	if(!x)x=++si;
	if(R<l){
		a[x].lazy1+=R-L+1,a[x].sum+=1ll*(R-L+1)*(r-l+1);return;
	}
	if(L<=l&&R>=r){
		a[x].sum+=1ll*(l-L+1+r-L+1)*(r-l+1)/2;
		a[x].lazy1+=l-L+1;a[x].lazy2++;
		return;
	}
	int mid=(1ll*l+r)>>1;
	pushdown(x,mid-l+1);
	if(L<=mid)change(a[x].l,l,mid);
	change(a[x].r,mid+1,r);
	update(x);
}
LL query(int x,int l,int r){
	if(!x|!a[x].sum)return 0;
	if(L<=l&&R>=r){
		return a[x].sum;
	}
	int mid=(1ll*l+r)>>1;LL ans=0;
	pushdown(x,mid-l+1);
	if(L<=mid)ans+=query(a[x].l,l,mid);
	if(R>mid)ans+=query(a[x].r,mid+1,r);
	return ans;
}
int main(){
	int n,w=1000000000,x;scanf("%d",&n);
	LL ans=0;r[0]=-1;L=R=w,change(a[0].l,1,inf);
	for(int i=1;i<=n;i++){
		scanf("%d%d",l+i,r+i);
		if(l[i]>r[i-1]+1){
			R=w-2,w-=l[i]-r[i-1]-1,L=w-1;
			ans+=query(a[0].l,1,inf);
			L++,R++,change(a[0].l,1,inf);
		}
		L=w,x=r[i]-l[i]+1,w+=x,R=w-1;
		ans+=query(a[0].l,1,inf);
		ans+=1ll*x*(x-1)/2;
		L++,R++,change(a[0].l,1,inf);
	}
	if(r[n]<1e9)R=w-2,w-=1e9-r[n]-1,L=w-1,ans+=query(a[0].l,1,inf);
	printf("%lld",ans);
	return 0;
} 
