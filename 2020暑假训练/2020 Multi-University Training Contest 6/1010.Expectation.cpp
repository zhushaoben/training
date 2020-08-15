#include<bits/stdc++.h>
using namespace std;
const int N=105,mo=998244353,MOD=998244353;
typedef long long LL;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
int a[N][N],b[N][N];
LL K[N][N];
LL gauss(int n){
    LL res=1;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n-1;j++){
            while(K[j][i]){
                int t=K[i][i]/K[j][i];
                for(int k=i;k<=n-1;k++)
                    K[i][k]=(K[i][k]-t*K[j][k]+MOD)%MOD;
                swap(K[i],K[j]);
                res=-res;
            }
        }
        res=(res*K[i][i])%MOD;
    }
    return (res+MOD)%MOD;
}
void work(){
	int n,m,u,v,w,ans=0;scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	memset(K,0,sizeof(K));
	for(u=1;u<n;u++)for(v=u+1;v<=n;v++)if(a[u][v])
		K[u][u]++,K[v][v]++,K[u][v]--,K[v][u]--;
	int ans1=qpow(gauss(n),mo-2);
	for(int i=0;i<32;i++){
		memset(K,0,sizeof(K));
		for(u=1;u<n;u++)for(v=u+1;v<=n;v++)if(a[u][v]&(1<<i))
			K[u][u]++,K[v][v]++,K[u][v]--,K[v][u]--;
		(ans+=gauss(n)*(1<<i)%mo)%=mo;
	}
	printf("%d\n",1ll*ans*ans1%mo);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
