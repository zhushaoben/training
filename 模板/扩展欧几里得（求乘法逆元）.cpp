#include<cstdio>
#define ll long long
inline void exgcd(ll a,ll b,ll &x,ll &y){//a,b,x,yͬax+by=gcd(a,b)�е�a,b,x,y
    if(!b){
        x=1,y=0;return;
    }
    ll t;
    exgcd(b,a%b,x,y);
    t=x,x=y,y=t-(a/b)*y;
}
inline ll Inverse(ll a,ll p){//��aģp�ĳ˷���Ԫ
	ll x,y;
	exgcd(a,p,x,y);
	return x;
}
int main(){
	return 0;
} 
