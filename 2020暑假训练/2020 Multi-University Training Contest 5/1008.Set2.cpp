#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=5e3+5; 
int f[N][N];
void Inverse(int p,int a[],int n){
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int inv[N],fac[N];
void init(int n){
	fac[0]=inv[0]=1;Inverse(mo,inv,n);
	for(int i=1;i<=n;i++)inv[i]=1ll*inv[i-1]*inv[i]%mo,fac[i]=1ll*i*fac[i-1]%mo;
}
int C(int n,int m){if(n<m||m<0)return 0;return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
int fc(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*inv[n]*fac[m]%mo*fac[n-m]%mo;
}
int k;
int dp(int n,int i){
	if(n<k+1)return 1;
	if(f[n][i]!=-1)return f[n][i];
	f[n][i]=0;
	for(int j=min(i-1,k+1);j;j--){
		(f[n][i]+=1ll*dp(n-k-1,i-j)*C(i-2,j-1)%mo*C(n-i,k-j+1)%mo*fc(n-1,k)%mo)%=mo;
	}
	return f[n][i];
}
void work(){
	int n;scanf("%d%d",&n,&k);
	for(int i=n;i>=0;i-=k+1){
		for(int j=0;j<=i;j++)f[i][j]=-1;
		if(i-k-1<0)for(int j=0;j<=i;j++)f[i][j]=1;
	}
	for(int i=1;i<n;i++)
		printf("%d ",dp(n,i));
	printf("%d\n",dp(n,n));
}
int main(){
	init(5e3+1);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
