/******************************************************************
�����ʷ�-�߶���ά������ 
******************************************************************/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 15050
struct Edge{
	int u,v,next,dis;
}e[maxn*2];
int edge_s,N,stree;//edge_sΪ����,N�����Ĵ�С,streeҪ������¼p 
int depth[maxn],fa[maxn],size[maxn],son[maxn],top[maxn],p[maxn],fp[maxn],fi[maxn],ma[maxn*3],mi[maxn*3],lazy[maxn*3];
/*
e��fi[]: �ڽӱ��� 
depth[u]: �����浱ǰ�ڵ�u�����
fa[u]: �������浱ǰ�ڵ�u�ĸ���
size[u]: ����������uΪ���������ڵ����
son[u]: �������浱ǰ�ڵ�u���ض���
top[u]: �������浱ǰ�ڵ�u���������Ķ��˽ڵ�
p[u]: �������浱ǰ�ڵ�u���߶����е�λ��
fp[]: ���������߶�����Ӧλ�ñ�����ǵ�ǰ�ĸ��ڵ�
ma[],mi[]: �߶����ڵ�ά����ֵ 
lazy[]: �߶��������� 
*/
void add_edge(int u,int v,int dis){
	e[++edge_s].next=fi[u],e[edge_s].v=v,e[edge_s].u=u,fi[u]=edge_s,e[edge_s].dis=dis;
	e[++edge_s].next=fi[v],e[edge_s].v=u,e[edge_s].u=v,fi[v]=edge_s,e[edge_s].dis=dis;
}
void dfs1(int x,int pre,int d){//��һ��dfs���fa,depth,size,son
	depth[x]=d,fa[x]=pre,size[x]=1;
	for(int i=fi[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==pre)continue;
		dfs1(v,x,d+1);size[x]+=size[v];
		if(size[v]>size[son[x]]||!son[x])son[x]=v;//Ŀǰ���ض��� 
	}
}
void dfs2(int x,int sp){//�ڶ���dfs���top��p
	top[x]=sp,p[x]=++stree,fp[stree]=x;
	if(!son[x])return;
	dfs2(son[x],sp);
	for(int i=fi[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa[x]||v==son[x])continue;
		dfs2(v,v);
	}
}
inline void update(int x){//�߶������� 
	ma[x]=max(ma[x<<1],ma[x<<1|1]),mi[x]=min(mi[x<<1],mi[x<<1|1]);
}
inline void push_down(int x){//lazy����·� 
	int tmp;
	if(lazy[x]){
		tmp=ma[x<<1],ma[x<<1]=-mi[x<<1],mi[x<<1]=-tmp,
		tmp=ma[x<<1|1],ma[x<<1|1]=-mi[x<<1|1],mi[x<<1|1]=-tmp,
		lazy[x<<1]^=1,lazy[x<<1|1]^=1,lazy[x]=0;
	}
}
void update_ne(int x,int l,int r,int L,int R){//�߶�������ȡ�� 
	int tmp;
	if(l==r){
		tmp=ma[x],ma[x]=-mi[x],mi[x]=-tmp;
		return;
	}
	if(l>=L&&r<=R){
		tmp=ma[x],ma[x]=-mi[x],mi[x]=-tmp,lazy[x]^=1;
		return;
	}
	push_down(x);
	int mid=(l+r)>>1;
	if(mid>=L)update_ne(x<<1,l,mid,L,R);
	if(mid<R)update_ne(x<<1|1,mid+1,r,L,R);
	update(x);
}
void negate(int u,int v){//·��ȡ�� 
	int f1=top[u],f2=top[v];
	while(f1!=f2){
		if(depth[f1]<depth[f2]){
			update_ne(1,1,N,p[f2],p[v]);
        	v = fa[f2];
        	f2 = top[v];
		}
		else{
			update_ne(1,1,N,p[f1],p[u]);
        	u = fa[f1];
       		f1 = top[u];
		}
	}
	if(u==v)return;
	if(depth[u]>depth[v])swap(u,v);
	update_ne(1,1,N,p[son[u]],p[v]);
}
int query(int x,int l,int r,int L,int R){//�߶���������ֵ��ѯ 
	if(l==r)return ma[x];
	if(L<=l&&R>=r)return ma[x];
	push_down(x);
	int mid=(l+r)>>1,tmp=-999999999;
	if(mid>=L)tmp=query(x<<1,l,mid,L,R);
	if(mid<R)tmp=max(tmp,query(x<<1|1,mid+1,r,L,R));
	return tmp;
} 
inline int find(int u,int v){//��ѯu->v·���ϱ�Ȩ�����ֵ
	int f1=top[u],f2=top[v];
	int tmp=-999999999;
	while(f1!=f2){
		if(depth[f1]<depth[f2]){
			tmp = max(tmp, query(1,1,N,p[f2],p[v]));
        	v = fa[f2],f2 = top[v];
		}
		else{
			tmp = max(tmp, query(1,1,N,p[f1],p[u]));
        	u = fa[f1],f1 = top[u];
		}
	}
	if(u==v)return tmp;
	if(depth[u]>depth[v])swap(u,v);
	return max(tmp,query(1,1,N,p[son[u]],p[v]));
}
inline void change_val(int x,int l,int r,int k,int val){//�߶��������޸� 
	if(l==r){
		mi[x]=ma[x]=val;
		return;
	}
	push_down(x);
	int mid=(l+r)>>1;
	if(mid>=k)change_val(x<<1,l,mid,k,val);
	else change_val(x<<1|1,mid+1,r,k,val);
	update(x);
}
inline void change(int x,int y){//�޸ĵ�x����Ϊy 
	int u=e[x<<1].u,v=e[x<<1].v;
	if(depth[u]<depth[v])change_val(1,1,N,p[v],y);
	else change_val(1,1,N,p[u],y);
}
int work(){
	int a,b,d;char s[20];
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		scanf("%d%d%d",&a,&b,&d);
		add_edge(a,b,d);
	}
	dfs1(1,0,1);dfs2(1,1);
	for(int i=1;i<edge_s;i+=2){
		int u=e[i].u,v=e[i].v;
		if(depth[u]<depth[v])change_val(1,1,N,p[v],e[i].dis);
		else change_val(1,1,N,p[u],e[i].dis);
	}
	return 0;
}
inline int get_lca(int u,int v){//��ѯu��v��lca 
	int f1=top[u],f2=top[v];
	while(f1!=f2){
		if(depth[f1]<depth[f2]){
        	v = fa[f2],f2 = top[v];
		}
		else{
        	u = fa[f1],f1 = top[u];
		}
	}
	if(u==v)return u;
	if(depth[u]>depth[v])swap(u,v);
	return u;
}
void init(){
	stree=edge_s=0;
	memset(son,0,sizeof(son)),memset(fi,0,sizeof(fi)),memset(lazy,0,sizeof(lazy));
}
int main(){
//	freopen("maintaintree.in","r",stdin);
//	freopen("maintaintree.out","w",stdout);
	init();
	work();
	return 0;
}

