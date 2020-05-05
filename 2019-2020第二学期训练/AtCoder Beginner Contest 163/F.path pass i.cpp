/*
�󲻾����κ���ɫΪi�Ľڵ��·���������������·����n*(n+1)/2��ȥ������
��Ȼ������������ɫΪi�Ľڵ�ɾ��������������CC
�����ǵĴ�С�ֱ�Ϊs1,s2,....,sm����ô�𰸾��ǡ�sj*(sj+1)/2
��������i������һ��CC�������С�ĵ�Ҫôû�и��ף����ڸ�����1Ϊ������Ҫô������ɫΪi
�ֲ��ѷ��֣�����һ����1�ڵ㣬��ֻ����Ϊһ��i�ʳ�����CC�Ĵ���
��Ϊ���Ƕ���һ���̶��ĸ��ף�Ҳ����һ���̶��ĸ��׵���ɫ��
���ڵ�1ȴ������Ϊ����һ��i�ʳ�����CC�Ĵ�����Ҫ���⿪���鴦��������CC��ΪO(n)
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long LL;
struct Edge{
	int next,to;
}edge[N*2];
int c[N],c1[N],fi[N],se,Size[N],Size1[N],n,Sizec[N];
LL ans[N];
inline void add_edge(int u,int v){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void dfs(int x,int fa){
	int w=(c[x]!=c[fa]?c[fa]:0),fa1=c1[w];
	c1[w]=x;Size[x]=1;
	for(int i=fi[x];i;i=edge[i].next){
		int v=edge[i].to;if(v==fa)continue;
		dfs(v,x);Size[x]+=Size[v];
	}
	if(c[x]==c[fa])return;
	ans[w]-=1ll*(Size[x]-Size1[x])*(Size[x]-Size1[x]+1)/2;
	if(c1[c[x]])Size1[c1[c[x]]]+=Size[x];
	else Sizec[c[x]]+=Size[x];
	c1[w]=fa1;
}
int main(){
	int u,v;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	dfs(1,0);
	for(int i=1;i<=n;i++)Sizec[i]=n-Sizec[i],ans[i]+=1ll*n*(n+1)/2-1ll*Sizec[i]*(Sizec[i]+1)/2,printf("%lld\n",ans[i]);
	return 0;
} 
