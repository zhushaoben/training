#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m1,m2,ma[N],mi[N];
int vis[N],match[N],T;
bool a[N][N];
inline void del_edge(int u,int v){a[u][v]=0;}
void init(){
	for(int i=1;i<=n;i++)ma[i]=n,mi[i]=1;
	for(int i=1;i<=n;i++)for(int j=n+1;j<=2*n;j++)a[i][j]=1;
	memset(vis,0,sizeof(vis)),memset(match,0,sizeof(match));
}
bool dfs(int x){
	if(vis[x]==T)return 0;
	vis[x]=T;
	for(int i=n+1;i<=n*2;i++){
		if(!a[x][i])continue;
		if(!match[i]||dfs(match[i])){
			match[x]=i,match[i]=x;return 1;
		}
	}
	return 0;
}
int work(){
	init();int l,r,x;
	for(int i=0;i<m1;i++){
		scanf("%d%d%d",&l,&r,&x);
		for(int j=1;j<l;j++)del_edge(j,x+n);
		for(int j=l;j<=r;j++)mi[j]=max(mi[j],x);
		for(int j=r+1;j<=n;j++)del_edge(j,x+n);
	}
	for(int i=0;i<m2;i++){
		scanf("%d%d%d",&l,&r,&x);
		for(int j=1;j<l;j++)del_edge(j,x+n);
		for(int j=l;j<=r;j++)ma[j]=min(ma[j],x);
		for(int j=r+1;j<=n;j++)del_edge(j,x+n);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<mi[i];j++)del_edge(i,j+n);
		for(int j=ma[i]+1;j<=n;j++)del_edge(i,j+n);
	}
	for(T=1;T<=n;T++)
		if(!dfs(T))return puts("-1"),0;
	for(int i=1;i<=n;i++){
		for(int j=1+n;j<=n*2;j++){
			if(!a[i][j]||match[j]<i)continue;
			if(match[i]==j)break;
			int x=match[j],y=match[i];
			match[x]=match[y]=0,match[j]=i,match[i]=j;T++;
			for(int k=1;k<=i;k++)vis[k]=T;
			if(dfs(x))break;
			match[j]=x,match[x]=j,match[i]=y,match[y]=i;
		}
	}
	printf("%d",match[1]-n);
	for(int i=2;i<=n;i++)printf(" %d",match[i]-n);
	puts("");
	return 0;
}
int main(){
	while(~scanf("%d%d%d",&n,&m1,&m2))work();
	return 0;
}
