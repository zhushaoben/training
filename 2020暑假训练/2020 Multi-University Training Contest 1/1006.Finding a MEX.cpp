#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	int next,to;
}edge[N*2],edge1[N*2]; 
int d[N],fi[N],se,fi1[N],se1,a[N],b[N];
inline void add_edge(int u,int v,Edge edge[]=edge,int fi[]=fi,int &se=se){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
set<int> S[N];
int *num[N];
void work(){
	int n,m,s,u,v,x,op,q;scanf("%d%d",&n,&m);s=sqrt(m)*4;
	se=se1=0;for(int i=1;i<=n;i++)d[i]=fi[i]=fi1[i]=0,scanf("%d",a+i),S[i].clear();
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),d[u]++,d[v]++,add(u,v);
	for(int i=1;i<=n;i++){
		for(int j=fi[i];j;j=edge[j].next){
			v=edge[j].to;
			if(d[v]>s)add_edge(i,v,edge1,fi1,se1);
		}
		if(d[i]>s){
			num[i]=new int[d[i]];
			for(int j=0;j<d[i];j++)num[i][j]=0;
			for(int j=fi[i];j;j=edge[j].next){
				v=edge[j].to;
				if(a[v]<d[i])num[i][a[v]]++;
			}
			for(int j=0;j<d[i];j++){
				if(!num[i][j]){
					S[i].insert(j);
				}
			}
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&u,&x);
			for(int j=fi1[u];j;j=edge1[j].next){
				v=edge1[j].to;
				if(a[u]<d[v]){
					num[v][a[u]]--;
					if(!num[v][a[u]])S[v].insert(a[u]);
				}
				if(x<d[v]){
					num[v][x]++;
					if(num[v][x]==1)S[v].erase(x);
				}
			}
			a[u]=x;
		}
		if(op==2){
			scanf("%d",&u);
			if(d[u]>s){printf("%d\n",*S[u].begin());}
			else{
				for(int i=0;i<=d[u];i++)b[i]=0;
				for(int j=fi[u];j;j=edge[j].next){
					int v=edge[j].to;
					if(a[v]<d[u])b[a[v]]++;
				}
				for(int i=0;i<=d[u];i++)if(!b[i]){printf("%d\n",i);break;}
			}
		}
	}
	for(int i=1;i<=n;i++)if(num[i])delete []num[i],num[i]=0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
