#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=2e6+5;
const ll mod=998244353;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int n;
ll fac[N+2],inv[N+2],ans[N+2];
ll qpow(ll x,ll k){
    ll ret=1;
    while(k){
        if(k&1) (ret*=x)%=mod;
        x*=x,x%=mod; k>>=1;
    }
    return ret;
}
void pre(){
    fac[0]=1;
    for(int i=1; i<=N; i++) fac[i]=fac[i-1]*i%mod;
    inv[N]=qpow(fac[N], mod-2);
    for(int i=N-1; ~i; i--) inv[i]=inv[i+1]*(i+1)%mod;
    for(int i=1; i<=N/2; i++) ans[i]=fac[i]*fac[i]%mod*inv[2*i+1]%mod;
}
int main(){
    pre();
    while(scanf("%d",&n)!=EOF) printf("%lld\n",ans[n]);
    return 0;
}
