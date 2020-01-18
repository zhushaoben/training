#include<bits/stdc++.h>
using namespace std;
#define maxn 85
#define maxs 6400
bitset<maxs*2> f[maxn][maxn];
int a[maxn][maxn];
int main(){
	int n,m,x;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&x),a[i][j]=abs(a[i][j]-x);
	f[0][1][maxs]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]|=(f[i][j-1]>>a[i][j])|(f[i][j-1]<<a[i][j]);
			f[i][j]|=(f[i-1][j]>>a[i][j])|(f[i-1][j]<<a[i][j]);
		}
	}
	int ans=80;
	for(int i=maxs;;i++)if(f[n][m][i]){ans=i-maxs;break;}
	printf("%d",ans);
	return 0;
} 
