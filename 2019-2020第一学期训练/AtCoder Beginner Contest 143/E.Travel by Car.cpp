#include<bits/stdc++.h>
using namespace std;
#define maxn 300
#define inf 0x1fffffffffffffff
#define LL long long
LL c[maxn+5][maxn+5],d[maxn+5][maxn+5];
int main(){
//	freopen("1.in","r",stdin);
	int n,m,L,u,v,x;scanf("%d%d%d",&n,&m,&L);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)c[i][j]=c[j][i]=d[i][j]=d[j][i]=inf;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&x);
		if(x<=L)c[u][v]=c[v][u]=x,d[u][v]=d[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=i+1;j<=n;j++){
				if(j==k)continue;
				if(c[i][k]!=inf&&c[j][k]!=inf){
					if(c[i][k]+c[j][k]<=L)c[j][i]=c[i][j]=min(c[i][j],c[i][k]+c[j][k]),d[i][j]=d[j][i]=1;
				}
//				if(d[i][k]!=inf&&d[j][k]!=inf)d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[j][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=i+1;j<=n;j++){
				if(j==k)continue;
				if(d[i][k]!=inf&&d[j][k]!=inf)d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[j][k]);
			}
		}
	}
	int q;scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",d[u][v]==inf?-1:d[u][v]-1);
	}
	return 0;
}
