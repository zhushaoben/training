#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 300
LL f[maxn+5][maxn+5][maxn+5],h[maxn+5]; 
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",h+i);memset(f,0x1f,sizeof(f));
	h[n++]=0;
	for(int i=1;i<=k;i++)for(int j=0;j<n;j++)f[0][i][j]=h[j];
	f[0][0][0]=h[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=min(k,i);j++){
			for(int k=0;k<n;k++){
//				if(k==i)continue;
				f[i][j][i]=min(f[i][j][i],f[i-1][j][k]+max(0ll,h[i]-h[k]));
				f[i][j+1][k]=min(f[i][j+1][k],f[i-1][j][k]);
			}
		}
	}
	LL ans=**f[maxn+1];
	for(int j=0;j<n;j++)ans=min(ans,f[n-1][k][j]);
	printf("%lld\n",ans);
	return 0;
}
