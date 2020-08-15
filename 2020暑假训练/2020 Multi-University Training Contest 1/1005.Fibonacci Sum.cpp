#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
 
const int P=1000000009;
const int INV2=500000005;
const int SQRT5=383008016;
const int INVSQRT5=276601605;
const int A1=691504013;
const int B1=308495997;
int A,B;
 
const int N=100005;
 
ll n,K,c;
ll fac[N],inv[N];
ll pa[N],pb[N];
 
inline void Pre(int n){
  fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%P;
  inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(P-P/i)*inv[P%i]%P;
  inv[0]=1; for (int i=1;i<=n;i++) inv[i]=inv[i]*inv[i-1]%P;
  pa[0]=1; for (int i=1;i<=n;i++) pa[i]=pa[i-1]*A%P;
  pb[0]=1; for (int i=1;i<=n;i++) pb[i]=pb[i-1]*B%P;
}
 
inline ll C(int n,int m){
  return fac[n]*inv[m]%P*inv[n-m]%P;
}
 
inline ll Pow(ll a,ll b){
  ll ret=1;
  for (;b;b>>=1,a=a*a%P)
    if (b&1)
      ret=ret*a%P;
  return ret;
}
 
inline ll Inv(ll x){
  return Pow(x,P-2);
}
ll qpow(ll a,ll b,ll p){
	ll ans=1;a%=p;
	while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p,b>>=1;
	}
	return ans;
}
inline void Solve(){
	A=qpow(A1,c,P),B=qpow(B1,c,P);
  ll Ans=0;
  Pre(K);
  for (int j=0;j<=K;j++){
    ll t=pa[K-j]*pb[j]%P,tem;
    tem=t==1?n%P:t*(Pow(t,n)-1+P)%P*Inv(t-1)%P;
    if (~j&1)
      Ans+=C(K,j)*tem%P,Ans%=P;
    else
      Ans+=P-C(K,j)*tem%P,Ans%=P;
  }
  Ans=Ans*Pow(INVSQRT5,K)%P;
  printf("%lld\n",Ans);
}
 
int main(){
  int T;
  scanf("%d",&T);
  while (T--){
    scanf("%lld%lld%lld",&n,&c,&K);
    Solve();
  }
}
