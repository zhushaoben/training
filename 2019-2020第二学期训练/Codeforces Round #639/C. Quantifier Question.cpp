#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge{
	int next,to;
}edge[N],edge1[N];
int fi[N],se,fi1[N],se1,s[N],que[N],S,T,s1[N];
char ans1[N];
inline void add_edge(int u,int v,int fi[]=fi,Edge edge[]=edge,int &se=se){edge[++se]={fi[u],v},fi[u]=se;}
void dfs(int x,int fi[]=fi,Edge edge[]=edge,int s[]=s){
	if(s[x])return;
	s[x]=1;
	for(int i=fi[x];i;i=edge[i].next)dfs(edge[i].to,fi,edge,s);
}
int main(){
//	freopen("1.in","r",stdin);
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d",&u,&v),s[u]++,add_edge(v,u),add_edge(u,v,fi1,edge1,se1);
	for(int i=1;i<=n;i++)if(!s[i])que[T++]=i;
	while(S<T){
		u=que[S++];
		for(int i=fi[u];i;i=edge[i].next){
			v=edge[i].to;
			if(!(--s[v]))que[T++]=v;
		}
	}
	for(int i=1;i<=n;i++)if(s[i])return puts("-1"),0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]||s1[i])ans1[i]='E';
		else ans1[i]='A',ans++;
		dfs(i),dfs(i,fi1,edge1,s1);
	}
	printf("%d\n",ans);
	puts(ans1+1);
	return 0;
}
