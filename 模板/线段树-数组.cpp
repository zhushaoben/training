#include<cstdio>
#define maxn 1<<18
long long a[maxn],sum[maxn],lazy[maxn],k;
void build(int l,int r,int x){//建树 
	if(l==r){sum[x]=a[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,x<<1|1);
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
void pushdown(int x,int s1,int s2){//标记下放 
	lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],
	sum[x<<1]+=lazy[x]*s1,sum[x<<1|1]+=lazy[x]*s2,lazy[x]=0;
}
void modify(int L,int R,int x,int l,int r,int w){//区间修改 
	if(L>=l&&R<=r){lazy[x]+=w,sum[x]+=(R-L+1)*w;return;}
	int mid=(L+R)>>1;
	if(lazy[x])pushdown(x,mid-L+1,R-mid);
	if(mid>=l)modify(L,mid,x<<1,l,r,w);
	if(mid<r)modify(mid+1,R,x<<1|1,l,r,w);
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
void change(int L,int R,int x,int l,int w){//单点修改 
	if(L==R){sum[x]+=w;return;}
	int mid=(L+R)>>1;
	if(mid>=l)change(L,mid,x<<1,l,w);
	else change(mid+1,R,x<<1|1,l,w);
	sum[x]+=w;
} 
long long query(int L,int R,int x,int l,int r){//区间查询 
	if(L>=l&&R<=r){return sum[x];}
	int mid=(L+R)>>1;
	long long ans=0;
	if(lazy[x])pushdown(x,mid-L+1,R-mid);
	if(mid>=l)ans+=query(L,mid,x<<1,l,r);
	if(mid<r)ans+=query(mid+1,R,x<<1|1,l,r);
	return ans;
}
int main(){
	int n,q,x,l,r,k,d;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=0;i<q;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%d%d",&l,&r,&k,&d);
			change(1,n,1,l,k);
			if(r>l)modify(1,n,1,l+1,r,d);
			if(r<n)change(1,n,1,r+1,-k-d*(r-l));
		}
		else{
			scanf("%d",&l);
			printf("%lld\n",query(1,n,1,1,l)+a[l]);
		}
	}
	return 0;
} 
