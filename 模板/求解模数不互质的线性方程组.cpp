#include<cstdio>
#include<cstdlib>
#define ll long long
inline ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
inline ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
inline void exgcd(ll a,ll b,ll &x,ll &y){//a,b,x,y同ax+by=gcd(a,b)中的a,b,x,y
    if(!b){
        x=1,y=0;return;
    }
    ll t;
    exgcd(b,a%b,x,y);
    t=x,x=y,y=t-(a/b)*y;
}
inline void merge(ll a1,ll m1,ll a2,ll m2,ll &a3,ll &m3){//将方程x=a1+k1m1和x=a2+k2m2合并为x=a3+k3m3; 
	ll d=gcd(m2,m1),a=a2-a1,q,y;
	if(a%d)exit(1);//无解
	m3=lcm(m1,m2);
	exgcd(m1/d,m2/d,q,y);
	a3=a/d*q*m1+a1;
	((a3%=m3)+=m3)%=m3;
} 
inline ll solve(ll a[],ll m[],ll n){//求解同余方程组 
	ll a1=a[0],m1=m[0];
	for(int i=1;i<n;i++){
		merge(a1,m1,a[i],m[i],a1,m1);
	}
	return (a1%m1+m1)%m1;//返回最小正整数解 
}
int main(){
	return 0;
} 
