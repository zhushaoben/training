#include<cstdio>
#define ll long long
inline void exgcd(ll a,ll b,ll &x,ll &y){//a,b,x,y同ax+by=gcd(a,b)中的a,b,x,y
    if(!b){
        x=1,y=0;return;
    }
    ll t;
    exgcd(b,a%b,x,y);
    t=x,x=y,y=t-(a/b)*y;
}
inline ll Inverse(ll a,ll p){//求a模p的乘法逆元
	ll x,y;
	exgcd(a,p,x,y);
	return x;
}
inline ll CRT(ll a[],ll m[],ll n){//求解同余方程组 
	ll M=1,_Mi,Mi,ans=0;//_Mi为Mi的乘法逆元(%m[i]意义下的) 
	for(int i=0;i<n;i++)M*=m[i];
	for(int i=0;i<n;i++){
		Mi=M/m[i];
		_Mi=Inverse(Mi,m[i]);
		ans=(ans+Mi*_Mi*a[i])%M;
	}
	if(ans<0)ans+=M;
	return ans;//返回最小正整数解 
}
int main(){
	return 0;
} 
