#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=1e9;
struct Node{
	int ma,pre,ma1,pre1;
}a[N*4],a1,ans;
int w[N],l1,r1,f[N];
Node update(Node &a,Node b){
	Node c=a;
	if(b.ma>=c.ma){
		if(b.ma>c.ma)c.ma1=c.ma,c.pre1=c.pre,c.ma=b.ma,c.pre=b.pre;
		else if(b.ma==c.ma&&(b.pre<c.pre))c.pre=b.pre;
	}
	else{
		if(b.ma>c.ma1||(b.ma==c.ma1&&b.pre<c.pre1))c.ma1=b.ma,c.pre1=b.pre;
	}
	if(b.ma1>c.ma1||(b.ma1==c.ma1&&b.pre1<c.pre1))c.ma1=b.ma1,c.pre1=b.pre1;
	return c;
}
void change(int l,int r,int x){
	if(l==r){a[x]=a1;return;}
	int mid=(l+r)>>1;
	if(l1<=mid)change(l,mid,x<<1);
	else change(mid+1,r,x<<1|1);
	a[x]=update(a[x<<1],a[x<<1|1]);
}
void query(int l,int r,int x){
	if(l1<=l&&r1>=r){ans=update(ans,a[x]);return;}
	int mid=(l+r)>>1;
	if(l1<=mid)query(l,mid,x<<1);
	if(r1>mid)query(mid+1,r,x<<1|1);
}
inline int calc(int x){return (x>0)-(x<0);}
void work(){
	int n,L,R,sum=0;scanf("%d%d%d",&n,&L,&R);n++;
	for(int i=1;i<n;i++)scanf("%d",w+i);
	a1={0,0,-inf,inf};l1=1;change(1,n,1);
	a1={-inf,inf,-inf,inf};
	for(int i=1;i<L;i++)sum+=w[i],l1=i+1,change(1,n,1);
	for(int i=L;i<n;i++){
		l1=max(1,i-R+1),r1=i-L+1,sum+=w[i];
		ans={-inf,inf,-inf,inf};query(1,n,1);a1=ans;
		f[i]=max(a1.ma+calc(sum-a1.pre),a1.ma1+calc(sum-a1.pre1));
		l1=i+1,a1={f[i],sum,-inf,inf},change(1,n,1);
	}
	printf("%d\n",f[n-1]);
}
int main(){
//	freopen("1002.in","r",stdin);
//	freopen("1.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
