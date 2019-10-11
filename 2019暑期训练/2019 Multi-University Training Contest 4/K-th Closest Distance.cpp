#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
#define maxn 100005
struct Node{
    int l,r,num;
}a[maxn*30];
int si,rt[maxn],w;
void insert(int &x,int y,int l,int r){
    x=++si;a[x]=a[y];a[x].num++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(w<=mid)insert(a[x].l,a[y].l,l,mid);
    else insert(a[x].r,a[y].r,mid+1,r);
}
int L,R,p,k,mid,l1,r1;
int query(int x,int y,int l,int r){
	if(l1<=l&&r1>=r)return a[y].num-a[x].num;
	int mid=(l+r)>>1,ans=0;
	if(l1<=mid)ans+=query(a[x].l,a[y].l,l,mid);
	if(r1>mid)ans+=query(a[x].r,a[y].r,mid+1,r);
	return ans; 
}
int cal(){
	int l=0,r=1000000;
	while(l<=r){
		mid=(l+r)>>1;l1=max(1,p-mid),r1=min(p+mid,1000000);
		if(query(rt[L-1],rt[R],1,1e6)>=k)r=mid-1;
		else l=mid+1;
	} 
	return l;
}
void work(){
    si=0;int m,n,ans=0;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w);
        insert(rt[i],rt[i-1],1,1e6); 
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&L,&R,&p,&k);
        L^=ans,R^=ans,p^=ans,k^=ans;
		printf("%d\n",ans=cal());
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--)work();
    return 0;
}
