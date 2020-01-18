#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct Edge{
	int next,to;
}edge[maxn*10];
int n,m,a,b,fi[maxn],se,dis1[maxn],dis2[maxn],que[maxn],s,t;
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
queue<int>q;
void bfs1(){
	dis1[1]=1;s=t=0;que[t++]=1;
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!dis1[v])dis1[v]=dis1[u]+1,que[t++]=v;
		}
	}
}
unordered_set<int>S[2];int f=0;
void bfs2(){
	dis2[1]=1;s=t=0;que[t++]=1;
	for(int i=2;i<=n;i++)S[f].insert(i);
	while(s<t){
		int u=que[s++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(S[f].find(v)!=S[f].end()){
                S[f].erase(v);
                S[!f].insert(v);
            }
		}
		for(auto it:S[f]){
			dis2[it]=dis2[u]+1;
			que[t++]=it;
		}
		S[f].clear();
        f=!f;
        if(S[f].empty())break;
	}
	S[f].clear();
}
void work(){
	se=0;memset(fi,0,sizeof(int)*(n+5)),memset(dis1,0,sizeof(int)*(n+5)),memset(dis2,0,sizeof(int)*(n+5));
	bool fl=0;int u,v;
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),add(u,v);
	bfs1();bfs2(); 
	if(!dis2[n]||(dis1[n]&&1ll*(dis1[n]-1)*a<1ll*(dis2[n]-1)*b))printf("%d\n",(dis1[n]-1)*a);
	else printf("%d\n",(dis2[n]-1)*b);
}
int main(){
	while(~scanf("%d%d%d%d",&n,&m,&a,&b))work();
	return 0;
}
