#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 100005
#define LL long long
int size,si,block[maxn],val[maxn],w[maxn],col[maxn],now[maxn];
struct Q{
	int x,y,t,id;
	bool operator <(const Q &b)const{//排序的第一关键字为x所在块，第二关键字为y所在块，第三关键字为询问之前的修改次数t 
		return (block[x]!=block[b.x])?block[x]<block[b.x]:(block[y]!=block[b.y]?block[y]<block[b.y]:t<b.t);
	}
}q[maxn];
struct C{
	int old,ne,x;
}ch[maxn];
struct Edge{
	int next,to;
}edge[maxn*2];
int fi[maxn],se,fa[maxn][18],stack[maxn],t,depth[maxn];
inline void add_edge(int u,int v){
	edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,
	edge[++se].next=fi[v],fi[v]=se,edge[se].to=u;
}
void out(int s){
	si++;
	while(t>s)block[stack[--t]]=si;
}
void dfs(int x,int s){ 
	for(int i=1;i<18;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa[x][0])continue;
		fa[v][0]=x,depth[v]=depth[x]+1,dfs(v,t);
		if(t-s>size)out(s);//如果当前子树栈中节点>=size,就自成一块 
	}
	stack[t++]=x;
	
}
void up(int &x,int d){
	for(int i=17;i>=0;i--){
		if(d&(1<<i))x=fa[x][i];
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	up(v,depth[v]-depth[u]);
	for(int i=17;i>=0;i--){
		if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	}
	if(u!=v)return fa[u][0];
	return u;
}
bool vis[maxn];
LL ans,ans1[maxn];int num[maxn];
void update(int x){//更新x(原来在路径上就删掉，不在就加入) 
	if(vis[x]){
		vis[x]=0;
		ans-=1ll*w[num[col[x]]--]*val[col[x]];
	}
	else{
		vis[x]=1;
		ans+=1ll*w[++num[col[x]]]*val[col[x]];
	}
}
void change(int x,int y){//将col[x]改成y 
	while(x!=y){
		if(depth[x]<depth[y])update(y),y=fa[y][0];
		else update(x),x=fa[x][0];
	}
}
void modify(int x,int y){//将x到y上的所有节点更新 
	if(!vis[x])col[x]=y;
	else{
		update(x);
		col[x]=y;
		update(x);
	}
}
int main(){
	int n,m,q1,u,v,op,t=0,cnt=0;
	scanf("%d%d%d",&n,&m,&q1);size=pow(n,0.6);
	for(int i=1;i<=m;i++)scanf("%d",val+i);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v);
	for(int i=1;i<=n;i++)scanf("%d",col+i),now[i]=col[i];
	depth[1]=1,dfs(1,0);
	while(t>0)block[stack[--t]]=si;//将最后剩下的节点加入最后一个块
	for(int i=0;i<q1;i++){
		scanf("%d%d%d",&op,&u,&v);
		if(op){
			if(block[u]>block[v])swap(u,v);//小优化，将所有询问x的块都变的比y小以防止query(u,v),query(v,u)算两次的情况 
			q[cnt].x=u,q[cnt].y=v,q[cnt].t=t,q[cnt].id=cnt;cnt++;
		}
		else{
			ch[t].x=u,ch[t].old=now[u],ch[t++].ne=v,now[u]=v;
		}
	}
	sort(q,q+cnt);u=v=1,t=0;
	for(int i=0;i<cnt;i++){
		while(t<q[i].t)modify(ch[t].x,ch[t].ne),t++;
		while(t>q[i].t)t--,modify(ch[t].x,ch[t].old);
		change(u,q[i].x);change(v,q[i].y);u=q[i].x,v=q[i].y;
		int Lca=lca(q[i].x,q[i].y);
		update(Lca);
		ans1[q[i].id]=ans;
		update(Lca);
	}
	for(int i=0;i<cnt;i++){
		printf("%lld\n",ans1[i]);
	}
	return 0;
} 
