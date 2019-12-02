#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int n,m,a[maxn],root[maxn],size,lazy[maxn*70],l[maxn*70],r[maxn*70],sum[maxn*70];//非动态开点则节点要开到n*logn*4 
int build(int L,int R){//建树 
	int k=size++;
	if(L==R){sum[k]=a[L-1];return k;}
	int mid=(L+R)>>1;
	l[k]=build(L,mid),r[k]=build(mid+1,R);
	sum[k]=sum[l[k]]+sum[r[k]];
	return k;
}
int modify(int history,int L,int R,int w,int l1,int r1){//区间修改,history是上个版本的当前节点的编号，L,R为当前节点范围，l1,l2为要修改的范围 
	int k=size++;
	lazy[k]=lazy[history],sum[k]=sum[history]+1ll*(r1-l1+1)*w,l[k]=l[history],r[k]=r[history];//克隆节点 
	if(l1<=L&&r1>=R){//整个区间都要被修改，打个标记返回 
		lazy[k]+=w;return k;
	}
	int mid=(L+R)>>1;
	if(l1<=mid)l[k]=modify(l[history],L,mid,w,l1,min(mid,r1));
	if(r1>mid)r[k]=modify(r[history],mid+1,R,w,max(mid+1,l1),r1);
	return k;
}
int change(int history,int L,int R,int w,int x){//单点修改 
	int k=size++;
	lazy[k]=lazy[history],sum[k]=sum[history]+w,l[k]=l[history],r[k]=r[history];//克隆节点
	if(L==R)return k;//如果是叶子节点就直接返回 
	int mid=(L+R)>>1;
	if(x<=mid)l[k]=change(l[history],L,mid,w,x);
	else r[k]=change(r[history],mid+1,R,w,x);
	return k;
}
int query(int x,int L,int R,int l1,int r1){//询问 
	if(l1<=L&&r1>=R)return sum[x];
	int mid=(L+R)>>1;
	int ans=lazy[x]*(r1-l1+1);//标记不能下放，因为子节点也是共用的,只能统计标记造成的影响 
	if(l1<=mid)ans+=query(l[x],L,mid,l1,min(mid,r1));
	if(r1>mid)ans+=query(r[x],mid+1,R,max(mid+1,l1),r1);
	return ans;
}
int main(){
	return 0;
} 
