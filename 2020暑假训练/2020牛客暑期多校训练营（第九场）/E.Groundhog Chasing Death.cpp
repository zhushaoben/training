#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100003;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
const ll mod=998244353,inv2=499122177;
ll sx,sy;
int p[N],cntx[N],cnty[N],tot,num;
int fx[N],fy[N];
vector<int> all;
ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k){
		if(k&1) ret*=x,ret%=mod;
		x*=x,x%=mod; k>>=1;
	}
	return ret;
}
void pre()
{
	ll x=sx,y=sy;
	for(int i=2; i<=38000; i++) if(!p[i]) {
		while(x%i==0) x/=i,cntx[i]++;
	}
//	if(x>1) p[++tot]=x,cnt[tot]++;
	
	for(int i=2; i<=38000; i++) if(!p[i]) {
		while(y%i==0) y/=i,cnty[i]++;
	}
	
	if(x == y && x>1) {
		all.push_back(x);
		fx[num]=1; fy[num]=1; num++;
	}
	
	x=sx,y=sy;
	for(int i=2; i<=38000; i++) if(!p[i]) {
		if(x%i==0 && y%i==0) {
			all.push_back(i);
			fx[num]=cntx[i];
			fy[num]=cnty[i];
			num++;
		}
	} 
//	if(y>1) p[++tot]=y,cnt[tot]++;
	
}
ll solve(ll b,ll d)
{
	if(b<=0 || d<=0) return 1;
	ll ret=1;
	for(int i=0; i<num; i++) {
		ll now=0;
		for(int j=1; j<=d; j++) {
			ll cy=1ll*fy[i]*j,cx=fx[i];
			if(cy<=cx) {
				now+=b*cy; now%=mod;
				continue;
			}
			ll n=min(b, cy/cx);
			now+=cx*(1+n)%mod*n%mod*inv2%mod; now%=mod;
			now+=(b-n)*cy%mod; now%=mod;
		}
		ret=(ret*qpow(all[i], now))%mod;
	}
	return ret;
}
int main()
{
	int a=read(),b=read(),c=read(),d=read(); sx=read(); sy=read();
	for(ll i=2; i<=38000; i++) {
		if(!p[i])
			for(ll j=i*i; j<=38000; j+=i) p[j]=1;
	}
	pre();
	ll res=0;
	res=solve(b, d);
	res=res*qpow(solve(a-1, d), mod-2)%mod;
	res=res*qpow(solve(b, c-1), mod-2)%mod;
	res*=solve(a-1, c-1); res%=mod;
	printf("%lld\n",res);
	return 0;
}
