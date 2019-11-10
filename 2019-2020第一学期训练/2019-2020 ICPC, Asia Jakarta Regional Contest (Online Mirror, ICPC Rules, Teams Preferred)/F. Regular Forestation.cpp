#include<bits/stdc++.h>
using namespace std;
#define maxn 4000
struct Edge{
	int next,to;
}edge[maxn*2+5];
int fi[maxn+5],se,root,si[maxn+5],n,sz;
inline void add_edge(int u,int v){edge[++se].next=fi[u],edge[se].to=v,fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){//find the point that satisfied the answer
	int S=0,fl=0;si[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);si[x]+=si[v];
		if(!S)S=si[v];
		else if(S==si[v])fl|=1;
		else fl|=2;
	}
	if(fl==1||(fl==0&&fi[x]&&fa)){
		if(n-si[x]==0||n-si[x]==S)root=x,sz=S;
	}
}
vector<int>rt;
int num,f[maxn+5];
void dfs2(int x,int fa){//find the core 
	si[x]=1;int ma=0;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs2(v,x);si[x]+=si[v];ma=max(ma,si[v]);
	}
	ma=max(ma,sz-si[x]);
	if(ma==num)rt.push_back(x);
	if(ma<num){num=ma,rt.clear(),rt.push_back(x);}
}
void dfs3(int x,int fa,int t){//calculate the f to compare two trees
	si[x]=f[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa||v==t)continue;
		dfs3(v,x,t);f[x]+=f[v]*si[v]*si[v];si[x]+=si[v];
	}
}
int main(){
	int u,v;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	if(!root)return puts("-1"),0;
	int w,fl,ans=0;
	for(int i=fi[root];i;i=edge[i].next){
		int v=edge[i].to;rt.clear(),num=maxn;dfs2(v,root);
		if(i==fi[root])dfs3(rt[0],0,root),w=f[rt[0]];
		else{
			fl=0;
			for(int i=0;i<(int)rt.size();i++){
				dfs3(rt[i],0,root);
				if(w==f[rt[i]]){fl=1;break;}
			}
			if(!fl)return puts("-1"),0;
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}
