#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define inf 0x1f1f1f1f
int f[maxn][3],g[maxn][3],dis[maxn][maxn][3],x[maxn],y[maxn],dr[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{2,1},{2,-1},{-2,-1},{-2,1}};
int s,n1,n,a[11][11];
void dfs(int x,int y,int now){
	if(dis[s][a[x][y]][0]<=now)return;
	dis[s][a[x][y]][0]=now;
	for(int i=0;i<8;i++){
		int x1=x+dr[i][0],y1=y+dr[i][1];
		if(x1<=0||x1>n||y1<=0||y1>n)continue;
		dfs(x1,y1,now+1);
	}
}
void build(){
	dfs(x[s],y[s],0);
	for(int i=1;i<=n1;i++){
		dis[s][i][1]=2-(x[s]==x[i])-(y[s]==y[i]);
		if(i==s)dis[s][i][2]=0;
		else if((x[s]+y[s]-x[i]-y[i])%2)dis[s][i][2]=inf;
		else{
			if(abs(x[s]-x[i])==abs(y[s]-y[i]))dis[s][i][2]=1;
			else dis[s][i][2]=2;
		}
	}
}
void work(int i,int j,int k){
	if(f[i][j]>f[i-1][k]+dis[i-1][i][j]+(j!=k)||(f[i][j]==f[i-1][k]+dis[i-1][i][j]+(j!=k)&&g[i][j]>g[i-1][k]+(j!=k)))
	f[i][j]=f[i-1][k]+dis[i-1][i][j]+(j!=k),g[i][j]=g[i-1][k]+(j!=k);
	for(int w=1;w<=n1;w++){
		if(f[i][j]>f[i-1][k]+dis[i-1][w][k]+dis[w][i][j]+(j!=k)||(f[i][j]==f[i-1][k]+dis[i-1][w][k]+dis[w][i][j]+(j!=k)&&g[i][j]>g[i-1][k]+(j!=k)))
		f[i][j]=f[i-1][k]+dis[i-1][w][k]+dis[w][i][j]+(j!=k),g[i][j]=g[i-1][k]+(j!=k);
	}
}
int main(){
	int w;scanf("%d",&n),n1=n*n;memset(dis,0x1f,sizeof(dis));
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&w),x[w]=i+1,y[w]=j+1,a[x[w]][y[w]]=w;
	for(int i=1;i<=n1;i++)s=i,build();
	memset(f,0x1f,sizeof(f));f[1][0]=f[1][1]=f[1][2]=0;
	for(int i=2;i<=n1;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)work(i,j,k);
	int ans=inf,ans1=0;
	for(int i=0;i<3;i++){
		if(ans>f[n1][i]||(ans==f[n1][i]&&ans1>g[n1][i]))ans=f[n1][i],ans1=g[n1][i];
	}
	printf("%d %d",ans,ans1);
	return 0;
}
