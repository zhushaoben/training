#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int a[N],s[3];
int prim[N*10],prime_n,pre[N*10];
LL sum[N],f[8][N];
void prime(){
    int m=N*10;
    for(int i=2;i<m;i++){
        if(!pre[i])prim[prime_n++]=i,pre[i]=i;
        for(int j=0;j<prime_n&&i*prim[j]<m;j++){
            pre[prim[j]*i]=prim[j];
            if(i%prim[j]==0)break;
        }
    }
}
void work(){
	int n;scanf("%d%d%d%d",&n,s,s+1,s+2);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+pre[a[i]];
	for(int i=0;i<8;i++)for(int j=0;j<=n;j++)f[i][j]=0;
	for(int i=0;i<8;i++){
		for(int k=1;k<=n;k++)f[i][k]=max(f[i][k],f[i][k-1]);
		for(int j=0;j<3;j++){
			if(i&(1<<j))continue;
			for(int k=s[j];k<=n;k++){
				f[i|(1<<j)][k]=max(f[i|(1<<j)][k],f[i][k-s[j]]+sum[k]-sum[k-s[j]]);
			}
		}
	}
	printf("%lld\n",f[7][n]);
}
int main(){
	prime();
	int t=1;
	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
