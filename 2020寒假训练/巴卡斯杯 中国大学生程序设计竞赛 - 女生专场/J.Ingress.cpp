#include<bits/stdc++.h>
using namespace std;
int a[20],b[20],dis[20][20],f[1<<17][17];
void work(){
	int n,m,k,l,s,u,v,w,ans=0;scanf("%d%d%d%d",&n,&m,&k,&l),s=1<<(n+1);
	memset(dis,0x1f,sizeof(dis));
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=0;i<m;i++){scanf("%d%d%d",&u,&v,&w),dis[u][v]=dis[v][u]=w;}
	memset(f,0x1f,sizeof(f));f[1][0]=0;
	for(int k=0;k<=n;k++)for(int i=0;i<=n;i++)for(int j=i+1;j<=n;j++)
		dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<s;i++){
		for(int j=0;j<=n;j++){
			if(i&(1<<j))for(int k=0;k<=n;k++){
				f[i|(1<<k)][k]=min(f[i|(1<<k)][k],f[i][j]+dis[j][k]);
			}
		}
		if(f[i][0]<=l){
			priority_queue<pair<int,int> >q;
			for(int j=0;j<=n;j++){
				if(i&(1<<j))q.push(make_pair(a[j],j));
			}
			w=0;
			for(int j=0;j<k;j++){
				pair<int,int>x=q.top();q.pop();
				w+=x.first;q.push(make_pair(max(0,x.first-b[x.second]),x.second));
			}
			ans=max(ans,w);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case %d: ",i);
		work();
	}
	return 0;
}
