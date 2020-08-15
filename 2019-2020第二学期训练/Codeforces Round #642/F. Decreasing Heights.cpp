#include<bits/stdc++.h>
using namespace  std;
typedef long long LL;
const int N=105;
const LL inf=0x1f1f1f1f1f1f1f1f;
LL a[N][N],f[N][N],ans;
int n,m;
void calc(LL x){
	memset(f,0x1f,sizeof(f));
	f[0][0]=a[0][0]-x;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(f[i][j]==inf)continue;
		if(a[i+1][j]-i-j-1>=x)f[i+1][j]=min(f[i+1][j],f[i][j]+a[i+1][j]-i-j-1-x);
		if(a[i][j+1]-i-j-1>=x)f[i][j+1]=min(f[i][j+1],f[i][j]+a[i][j+1]-i-j-1-x);
	}
	ans=min(ans,f[n-1][m-1]);
}
void work(){
	scanf("%d%d",&n,&m);ans=inf;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%lld",a[i]+j);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
		if(a[i][j]-i-j<=**a)calc(a[i][j]-i-j);
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
