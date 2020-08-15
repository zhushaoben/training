#include <bits/stdc++.h>
using namespace std;
#define maxn 505
struct Edge{
	int next,to;
}edge[maxn*maxn*2];
int n,m,fi[maxn],se,match[maxn],f[maxn],pre[maxn],tim[maxn],vis[maxn],st;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
//����lca 
int lca(int x,int y){
	for(++st;;swap(x,y))if(x){
		x=find(x);
		if(tim[x]==st)return x;
		else tim[x]=st,x=pre[match[x]];
	}
}
int que[maxn],s,t;
void shrink(int u,int v,int l){//�滷���� 
	while(find(u)!=l){
		pre[u]=v;v=match[u];
		if(vis[v]==2)vis[v]=1,que[t++]=v;
		if(find(u)==u)f[u]=l;
		if(find(v)==v)f[v]=l;
		u=pre[v];
	}
}
//Ѱ������· 
bool aug(int S){
	for(int i=1;i<=n;i++)vis[i]=pre[i]=0,f[i]=i;
	s=t=0;que[t++]=S,vis[S]=1;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(vis[v]==2||find(u)==find(v))continue;//������Ѵ����滷�ϻ�����B��� 
			if(!vis[v]){//δ���ʹ� 
				vis[v]=2;pre[v]=u;
				if(!match[v]){//�ҵ�����· 
					for(int x=v,la;x;x=la)
						la=match[pre[x]],match[x]=pre[x],match[pre[x]]=x;
					return 1;
				}
				vis[match[v]]=1,que[t++]=match[v];//��v��ԭƥ�����ΪA��� 
			}
			else{//�ҵ��滷 
				int l=lca(u,v);
				shrink(u,v,l),shrink(v,u,l);
			}
		}
	}
	return 0;
}
void work(){
	int u,v,ans=0;se=0;
	memset(fi,0,sizeof(int)*(n+5)),memset(match,0,sizeof(int)*(n+5));
	for(int i=0;i<m;i++)
		scanf("%d%d",&u,&v),add(u,v);
	for(int i=1;i<=n;i++)
		if(!match[i])ans+=aug(i);
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
}
