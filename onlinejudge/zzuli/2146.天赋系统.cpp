#include<bits/stdc++.h>
using namespace std;
const int N=20,M=1005,mo=1e9+7;
int d[N],c[M],a[N],fp[N],f[1<<15][M],ans[M];
vector<int>V[N],V1[N];
void work(){
	int n,m,k,u,v,si=0;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)d[i]=0,V[i].clear(),V1[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=0;i<k;i++)
		scanf("%d%d",&u,&v),V[u].push_back(v),V1[v].push_back(u),d[v]++;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(!d[j]){
				d[j]=123,a[i]=j,fp[j]=i;
				for(auto x:V[j])d[x]--;
				break;
			}
		}
		if(!a[i]){si=i+1;break;}
	}
	if(!si&&a[n-1])si=n;
	memset(f,0,sizeof(f)),f[0][0]=1;
	for(int i=0;i<si;i++){
		int w=0;
		for(auto x:V1[a[i]])v=fp[x],w|=(1<<v);
		for(int s=(1<<i);s<(1<<(i+1));s++){
			if((s&w)==w)for(int j=c[a[i]];j<=m;j++)(f[s][j]+=f[s][j-c[a[i]]]+f[s^(1<<i)][j-c[a[i]]])%=mo;
		}
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<(1<<si);i++)for(int j=1;j<=m;j++)(ans[j]+=f[i][j])%=mo;
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
