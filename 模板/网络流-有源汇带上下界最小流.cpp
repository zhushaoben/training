#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define maxn 60
#define maxe 550
struct Edge{
	int next,to,w,fl;
}edge[maxe];
int n,m,s,t,ss,tt,fi[maxn],se,flow[maxn],depth[maxn],que[maxn],first,last;
inline void add_edge(int u,int v,int w){
	edge[++se].next=fi[u],edge[se].to=v,edge[se].w=w,fi[u]=se,edge[se].fl=w,
	edge[++se].next=fi[v],edge[se].to=u,edge[se].w=edge[se].fl=0,fi[v]=se;
}
inline int readint(){
    register int res = 0;
    register char tmp = getchar();
    while(!isgraph(tmp))tmp=getchar();
    while(isgraph(tmp))res=((res+(res)<<2)<<1)+(tmp^0x30),tmp=getchar();
    return res;
}
inline void init(){
	s=0,t=n+1,ss=t+1,tt=ss+1,se=1,memset(fi,0,sizeof(fi)),memset(flow,0,sizeof(flow));
}
inline bool bfs(){
	memset(depth,0,sizeof(depth)),first=last=0,que[last++]=ss,depth[ss]=1;
	while(first<last){
		int x=que[first++];
		for(int i=fi[x];i;i=edge[i].next){
			int v=edge[i].to;
			if(depth[v]==0&&edge[i].w){
				depth[v]=depth[x]+1,que[last++]=v;
			}
		}
	}
	return depth[tt];
}
int dfs(int x,int fl){
	if(x==tt||!fl)return fl;
	int tmp=0,t;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(depth[v]==depth[x]+1){
			t=dfs(v,min(fl-tmp,edge[i].w));
			edge[i].w-=t,edge[i^1].w+=t,tmp+=t;
		}
	}
	return tmp;
}
inline int dinic(){
	int tot=0,x;
	while(bfs()){
		while(x=dfs(ss,0x3f3f3f))tot+=x;
	}
	return tot;
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<m;i++){
		int u=readint(),v=readint(),w=readint();
		add_edge(u,v,0x3f3f3f),flow[u]-=w,flow[v]+=w;
	}
	int sum=0,f1;
	for(int i=s;i<=t;i++){
		if(flow[i]>0)add_edge(ss,i,flow[i]),sum+=flow[i];
		if(flow[i]<0)add_edge(i,tt,-flow[i]);
	}
	f1=dinic();//先求一遍ss->tt最大流 
	add_edge(t,s,0x3f3f3f);//连边t->s,inf 
	if(sum!=f1+dinic()){//求ss->tt最大流  
		printf("impossible\n");return 0;
	}
	printf("%d\n",edge[se-1].fl-edge[se-1].w);//答案即为边t->s,inf的实际流量
	return 0;
}
