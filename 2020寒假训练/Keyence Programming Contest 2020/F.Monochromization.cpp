#include<bits/stdc++.h>
using namespace std;
const int N=11,mo=998244353;
char s[N][N];
int inv[N],fac[N],f[N][N],g[N][N],w[N],v[N];
//f[i][j] indicate the number of ways that print a i*j rectangle
//g[i][j] indicate the number of ways that print a i*j L shape
void init(){
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2;i<=10;i++)fac[i]=fac[i-1]*i,inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for(int i=2;i<=10;i++)inv[i]=1ll*inv[i]*inv[i-1]%mo;
}
void add(int &x,int y){(x+=y)%=mo;}
int mul(int x){return x;}
template<class... T> int mul(int x,T... y){return 1ll*x*mul(y...)%mo;}
inline int C(int n,int m){return 1ll*fac[n]*inv[n-m]%mo*inv[m]%mo;}
int main(){
	init();
	int n,m,s1,s2;scanf("%d%d",&n,&m),s1=(1<<n),s2=(1<<m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++)if(s[i][j]=='#')w[i]|=(1<<j),v[j]|=(1<<i);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){//we calculate f and g used principle of inclusion-exclusion.  
			if(!i||!j){f[i][j]=1,g[i][j]=1<<(i+j);continue;}
			for(int k=1;k<=i;k++)add(f[i][j],mul(k&1?1:mo-1,C(i,k),1<<k,f[i-k][j])),
			add(g[i][j],mul(k&1?1:mo-1,C(i,k),1<<k,g[i-k][j]));
			for(int k=1;k<=j;k++)add(f[i][j],mul(k&1?1:mo-1,C(j,k),1<<k,f[i][j-k])),
			add(g[i][j],mul(k&1?1:mo-1,C(j,k),1<<k,g[i][j-k]));
			for(int k=1;k<=i;k++)for(int l=1;l<=j;l++){
				add(f[i][j],mul((k+l)&1?1:mo-1,C(i,k),C(j,l),2,f[i-k][j-l]));
				add(g[i][j],mul((k+l)&1?1:mo-1,C(i,k),C(j,l),2,g[i-k][j-l]));
			}
		}
	}
	int ans=0;
	for(int i=1;i<s1;i++){
		for(int j=1;j<s2;j++){
			bool fl=0;int a=0,b=0;
			for(int k=0;k<n;k++)if(i&(1<<k))a++,fl|=(w[k]&j)==j||((~w[k])&j)==j;
			for(int k=0;k<m;k++)if(j&(1<<k))b++,fl|=(v[k]&i)==i||((~v[k])&i)==i;
			if(!fl)add(ans,g[n-a][m-b]);
		}
	}
	printf("%d",(ans+f[n][m])%mo);
	return 0;
}
