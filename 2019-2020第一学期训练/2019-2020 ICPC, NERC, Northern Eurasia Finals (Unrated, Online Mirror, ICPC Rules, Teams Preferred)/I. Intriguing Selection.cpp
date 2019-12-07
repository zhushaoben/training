#include<bits/stdc++.h>
using namespace std;
#define maxn 205
struct Edge{
	int pre,to,nex;
}edge[maxn*maxn*4];
int a[maxn*2],fi[maxn*2],la[maxn*2],se,si;
inline void add_edge(int u,int v){
	edge[++se].pre=la[u];
	edge[la[u]].nex=se;
	edge[se].to=v,la[u]=se;
	edge[se].nex=0;
	if(!fi[u])fi[u]=se;
}
inline void add(int u,int v){printf("? %d %d\n",u,v),fflush(stdout),add_edge(u,v),add_edge(v,u);}
inline void del(int x){
	la[x]=edge[la[x]].pre;
	if(!la[x])fi[x]=0;
	else edge[fi[x]].nex=0;
}
char re;
void work(){
	int n,x=1,x1;scanf("%d",&n);
	se=0,si=0,memset(fi,0,sizeof(int)*(n*2+5)),memset(la,0,sizeof(int)*(n*2+5));
	while(x<=n)x<<=1;
	for(int i=1;i<=x;i++)a[i]=i;
	x1=x;while(x1>=2){
		si=1;
		for(int i=1;i<=x1;i+=2){
			add(a[i],a[i+1]);cin>>re;
//			if(n==4&&x1==8&&i==1&&re[0]=='<'){puts("WA");exit(0);}
			if(re=='<')a[si++]=a[i];
			else a[si++]=a[i+1];
		}
		x1>>=1;
	}
	int mi=a[1],now;
	for(int k=n-1;k;k--){
		if(x<n*2){
			x++,now=x,printf("? %d %d\n",now,mi),fflush(stdout);cin>>re;
			if(re=='<')continue;
			for(int i=fi[mi];i;i=edge[i].nex){
				int v=edge[i].to;del(v);
				add(now,v);cin>>re;
				if(re=='>')now=v;
			}
			mi=now;
			continue;
		}
		now=edge[fi[mi]].to;del(now);
		for(int i=fi[mi];i;i=edge[i].nex){
			int v=edge[i].to;if(v==now)continue;
			del(v),add(now,v);cin>>re;
			if(re=='>')now=v;
		}
		mi=now;
	}
	printf("!\n"),fflush(stdout);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
