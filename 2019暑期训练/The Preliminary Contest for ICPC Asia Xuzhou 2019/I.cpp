#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
int a[maxn],p[maxn];
vector<int>v[maxn];
LL sum[maxn<<2],M,lazy[maxn<<2],k;
void build(int n){//建树 
	M=1;while((M<<=1)<n);
	M--;
	for(int i=1;i<=n;i++){
		sum[i+M]=a[i];
	} 
	for(int i=M;i>0;i--){
		sum[i]=sum[i<<1]+sum[i<<1|1]; 
	}
}
void change(int x,int y){//单点修改 
	x+=M;
	sum[x]+=y;
	while(x>>=1){
		sum[x]+=y;
	}
}
void modify(int l,int r,int w){//区间修改
	if(l>r)return;
	if(l==r){change(l,w);return;}
	int d=1;
	sum[l+M]+=w,sum[r+M]+=w;//注:下面的操作不会更新端点的值，所以提前将端点更新 
	for(l+=M,r+=M;l^r^1;l>>=1,r>>=1){
		if(~l&1)sum[l^1]+=w*d,lazy[l^1]+=w;//在对应的右子节点打个标记，更新sum的值 
		if(r&1)sum[r^1]+=w*d,lazy[r^1]+=w;//在对应的左子节点打个标记，更新sum的值 
		d<<=1;
		sum[l>>1]=sum[l]+sum[l^1]+lazy[l>>1]*d;//更新两个父节点的值,其中d表示父节点表示区间的长度 
		sum[r>>1]=sum[r]+sum[r^1]+lazy[r>>1]*d;
	}
	while(l>>=1)d<<=1,sum[l]=sum[l<<1]+sum[l<<1|1]+lazy[l]*d;//更新路径上节点的sum值 
}
int query_node(int l){//单点查询
	int x=l+M,ans=0;
	while(x>>=1){
		if(lazy[x])ans+=lazy[x];
	}
	return sum[l+M]+ans;
}
LL query(int l,int r){//区间查询 (区间和)
	if(l>r)return 0;
	if(l==r)return query_node(l);
	int L=0,R=0,d=1;//L，R分别记录所求区间中有多少个节点处于左右端点所在的节点中，d记录所在层次的节点代表的区间长度 
	LL ans=0;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
		if(lazy[l])ans+=L*lazy[l];//计算lazy[l]影响的值 
		if(lazy[r])ans+=R*lazy[r];//计算lazy[r]影响的值 
		if(~l&1)ans+=sum[l^1],L+=d;//左端点所在的点是左子节点，则对应的右子节点处于区间中，更新L的值 
		if(r&1)ans+=sum[r^1],R+=d;
		d<<=1;
	}
	ans+=lazy[l]*L,ans+=lazy[r]*R,L+=R;
	while(l>>=1){//计算路径上的lazy造成的影响 
		if(lazy[l])ans+=lazy[l]*L;
	}
	return ans;
}
struct Node{
	int l,r,k;LL ans;
	bool operator < (const Node &b)const{
		return r<b.r;
	}
}w[maxn];
bool cmp(Node a,Node b){
	return a.k<b.k;
}
int main(){
	int n,m;scanf("%d%d",&n,&m);build(n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),p[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i<<1;j<=n;j+=i){
			int l=p[i],r=p[j];if(l>r)swap(l,r);
			v[r].push_back(l);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&w[i].l,&w[i].r);w[i].k=i;
	}sort(w+1,w+m+1);
	int now=1;
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			modify(1,j,1);
		}
		while(w[now].r==i){
			w[now].ans=query(w[now].l,w[now].l),now++;
		}
	}
	sort(w+1,w+m+1,cmp);
	for(int i=1;i<=m;i++)printf("%lld\n",w[i].ans);
	return 0;
}
