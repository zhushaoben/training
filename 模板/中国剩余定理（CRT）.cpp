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
inline ll CRT(ll a[],ll m[],ll n){//���ͬ�෽���� 
	ll M=1,_Mi,Mi,ans=0;//_MiΪMi�ĳ˷���Ԫ(%m[i]�����µ�) 
	for(int i=0;i<n;i++)M*=m[i];
	for(int i=0;i<n;i++){
		Mi=M/m[i];
		_Mi=Inverse(Mi,m[i]);
		ans=(ans+Mi*_Mi*a[i])%M;
	}
	if(ans<0)ans+=M;
	return ans;//������С�������� 
}
int main(){
	return 0;
} 
