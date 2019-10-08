#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std; 
const int N=1000003;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll phi[N+2],p[N+2],tot;
bool flg[N];
ll qpow(ll x,ll k,ll mod)
{
	ll ret=1;
	while(k){
		if(k&1) ret*=x,ret%=mod;
		x*=x,x%=mod; k>>=1;
	}
	return ret;
}
void pre(){
    phi[1]=1;
    for(int i=2;i<=N;++i) {
        if(!flg[i]) p[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&i*p[j]<=N;++j) {
            flg[i*p[j]]=1;
            if(i%p[j]==0) {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            } else {
                phi[i*p[j]]=phi[i]*phi[p[j]];
            }
        }
    }
}
ll work1(ll x,ll k,ll mod){
	ll ret=1;bool fl=0;
	while(k){
		if(k&1) ret*=x,fl=(ret>mod)|fl,ret%=mod;
		x*=x,fl=(x>mod)|fl,x%=mod; k>>=1;
	}
	return ret+(fl?mod:0);
}
ll work(ll a,ll b,ll m)
{
	if(m==1) return 0;
	if(b==0) return 1;
	if(b==1) return a%m;
	if(b==2) return qpow(a,a,m);
	if(b==3) return qpow(a,work1(a,a,phi[m]),m);
	if(a==2&&b==4)return (1<<16)%m;
	if(a==2&&b==5)return qpow(2,1<<16,m); 
	ll res=work(a, b-1, phi[m]);
	return qpow(a, res+phi[m], m);
}
void solve()
{
	ll a=read(),b=read(),m=read();
	if(b==0){
		printf("%lld\n",1%m); return;
	}
	ll ans=work(a, b, m);
//	ll ans=qpow(a, work(a, b-1, phi[m])+phi[m], m);
	printf("%lld\n",ans);
}
int main()
{
	pre();
	int T=read();
	while(T--) solve();
}
