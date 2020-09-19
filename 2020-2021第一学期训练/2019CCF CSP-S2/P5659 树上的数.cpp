#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
struct Edge{
	int next,to;
}edge[N*2];
int a[N],b[N],fi[N],se,p[N];
inline void add_edge(int u,int v){edge[++se]={fi[u],v},fi[u]=se;}
inline void add(int u,int v){add_edge(u,v),add_edge(v,u);}
void work(){
	int n,u,v;scanf("%d",&n);
	se=1,memset(fi,0,(n+1)<<2);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]=i;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v);
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
