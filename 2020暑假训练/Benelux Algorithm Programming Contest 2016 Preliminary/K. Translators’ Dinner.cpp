#include <bits/stdc++.h>
using namespace std;
const int N=205;
struct Edge{
	int next,to;
}edge[N*N*2];
int n,fi[N],se,match[N],f[N],pre[N],tim[N],vis[N],st;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int lca(int x,int y){
	for(++st;;swap(x,y))if(x){
		x=find(x);
		if(tim[x]==st)return x;
		else tim[x]=st,x=pre[match[x]];
	}
}
int que[N],s,t;
void shrink(int u,int v,int l){
	while(find(u)!=l){
		pre[u]=v;v=match[u];
		if(vis[v]==2)vis[v]=1,que[t++]=v;
		if(find(u)==u)f[u]=l;
		if(find(v)==v)f[v]=l;
		u=pre[v];
	}
} 
bool aug(int S){
	for(int i=1;i<=n;i++)vis[i]=pre[i]=0,f[i]=i;
	s=t=0;que[t++]=S,vis[S]=1;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(vis[v]==2||find(u)==find(v))continue;
			if(!vis[v]){
				vis[v]=2;pre[v]=u;
				if(!match[v]){ 
					for(int x=v,la;x;x=la)
						la=match[pre[x]],match[x]=pre[x],match[pre[x]]=x;
					return 1;
				}
				vis[match[v]]=1,que[t++]=match[v];
			}
			else{
				int l=lca(u,v);
				shrink(u,v,l),shrink(v,u,l);
			}
		}
	}
	return 0;
}
void init(){se=0;memset(fi,0,sizeof(int)*(n+5)),memset(match,0,sizeof(int)*(n+5));}
vector<int> b[N];
bool vis2[N];
int main(){
	int m,u,v;
	scanf("%d%d",&m,&n);
	if(n&1){puts("impossible");return 0;}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&u,&v);
		b[u+1].push_back(i),b[v+1].push_back(i);
	}
	for(int i=1; i<=m; i++) {
		auto j=b[i].begin(),k=j,ed=b[i].end();
		for(;j!=ed;j++)for(k=j,k++;k!=ed;k++)
			add(*j,*k);
	}
	for(int i=1;i<=n;i++){
		if(!match[i])if(!aug(i)){ puts("impossible"); return 0; }
	}
	for(int i=1; i<=n; i++) if(!vis2[i]) {
		printf("%d %d\n",i-1,match[i]-1);
		vis2[i]=vis2[match[i]]=1;
	}
	return 0;
}
