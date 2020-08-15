#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 50005
struct Edge{
	int u,v,next;
}e[maxn*2];
typedef long long LL;
int edge_s,N,stree;//edge_s为边数,N是树的大小,stree要辅助记录p 
int depth[maxn],fa[maxn],size[maxn],son[maxn],top[maxn],p[maxn],fp[maxn],fi[maxn],lazy[maxn*3];
LL sum[maxn*3];
/*
e和fi[]: 邻接表存边 
depth[u]: 来保存当前节点u的深度
fa[u]: 用来保存当前节点u的父亲
size[u]: 用来保存以u为根的子树节点个数
son[u]: 用来保存当前节点u的重儿子
top[u]: 用来保存当前节点u的所在链的顶端节点
p[u]: 用来保存当前节点u在线段树中的位置
fp[]: 用来保存线段树相应位置保存的是当前哪个节点
lazy[]: 线段树懒惰标记 
*/
void add_edge(int u,int v){
	e[++edge_s].next=fi[u],e[edge_s].v=v,e[edge_s].u=u,fi[u]=edge_s;
	e[++edge_s].next=fi[v],e[edge_s].v=u,e[edge_s].u=v,fi[v]=edge_s;
}
void dfs1(int x,int pre,int d){//第一遍dfs求出fa,depth,size,son
	depth[x]=d,fa[x]=pre,size[x]=1;
	for(int i=fi[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==pre)continue;
		dfs1(v,x,d+1);size[x]+=size[v];
		if(size[v]>size[son[x]]||!son[x])son[x]=v;//目前的重儿子 
	}
}
void dfs2(int x,int sp){//第二遍dfs求出top和p
	top[x]=sp,p[x]=++stree,fp[stree]=x;
	if(!son[x])return;
	dfs2(son[x],sp);
	for(int i=fi[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa[x]||v==son[x])continue;
		dfs2(v,v);
	}
}
inline void update(int x){//线段树更新 
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
inline void push_down(int x,int s1,int s2){//lazy标记下放 
	int tmp;
	if(lazy[x]){
		sum[x<<1]+=1ll*lazy[x]*s1,sum[x<<1|1]+=1ll*lazy[x]*s2;
		lazy[x<<1]+=lazy[x],lazy[x<<1|1]+=lazy[x],lazy[x]=0;
	}
}
int L,R,w;
LL query(int x,int l,int r){
	if(L<=l&&R>=r)return sum[x];
	int mid=(l+r)>>1;LL ans=0;
	push_down(x,mid-l+1,r-mid);
	if(mid>=L)ans+=query(x<<1,l,mid);
	if(mid<R)ans+=query(x<<1|1,mid+1,r);
	return ans;
} 
LL find(int x){
	LL ans=0;int f1;
	do{
		f1=top[x];
		L=p[f1],R=p[x];
		ans+=query(1,1,N);
		x=fa[f1];
	}while(f1!=1);
	return ans;
}
inline void change_val(int x,int l,int r){
	if(L<=l&&R>=r){sum[x]+=1ll*w*(r-l+1),lazy[x]+=w;return;}
	int mid=(l+r)>>1;
	push_down(x,mid-l+1,r-mid);
	if(L<=mid)change_val(x<<1,l,mid);
	if(R>mid)change_val(x<<1|1,mid+1,r);
	update(x);
}
inline void change(int x){
	int f1;
	do{
		f1=top[x];
		L=p[f1],R=p[x],w=2;
		change_val(1,1,N);
		x=fa[f1];
	}while(f1!=1);
}
LL b1[maxn],ans,tim;
int work(){
	int u,v,q,op;ans=tim=0;
	scanf("%d%d",&N,&q);
	for(int i=1;i<N;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs1(1,0,1);dfs2(1,1);
	for(int i=0;i<q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&u,&v);
			ans+=v-depth[u]-1,tim++;
			change(u);
		}
		else if(op==2){
			scanf("%d",&u);
			b1[u]=max(b1[u],find(u)+ans-tim*(depth[u]-1));
		}
		else{
			scanf("%d",&u);
			printf("%lld\n",find(u)+ans-tim*(depth[u]-1)-b1[u]);
		}
	}
	return 0;
}
void init(){
	stree=edge_s=0;
	memset(son,0,sizeof(son)),memset(fi,0,sizeof(fi)),memset(lazy,0,sizeof(lazy));
	memset(b1,0,sizeof(b1)),memset(sum,0,sizeof(sum));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)init(),work();
	return 0;
}

