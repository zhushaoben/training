#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
int prim[maxn/5],prime_n,pre[maxn];
bool nt_pr[maxn]={1,1};
void prime(){
    for(int i=2;i<maxn;i++){
        if(!nt_pr[i])prim[prime_n++]=i,pre[i]=i;
        for(int j=0;j<prime_n&&i*prim[j]<maxn;j++){
            nt_pr[prim[j]*i]=1,pre[prim[j]*i]=prim[j];
            if(i%prim[j]==0)break;
        }
    }
}
LL qmul(__int128 a,__int128 b,__int128 p){
	return ((a*b)%p);
	LL ans=0;
	while(b){
		if(b&1)ans=(ans+a)%p;
		a=(a<<1)%p,b>>=1;
	}
	return ans;
}
LL qpow(LL a,LL b,LL p){
	LL ans=1;
	while(b){
		if(b&1)ans=qmul(ans,a,p);
		a=qmul(a,a,p),b>>=1;
	}
	return ans;
}
bool Miller_Rabin(LL x){
	for(int i=0;i<10;i++)if(x==prim[i])return 1;
	if(x%2==0)return 0;
	LL k=x-1,l=0;
	while(!(k&1))k>>=1,l++;
	for(int i=0;i<10;i++){
		LL b=qpow(prim[i],k,x),c;
		for(int j=1;j<=l;j++){
			c=qmul(b,b,x);
			if(c==1&&b!=1&&b!=x-1)return 0;
			b=c;
		}
		if(b!=1)return 0;
	}
	return 1;
} 
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL n,k,p,a[30],b[30],si,fac[maxn];
LL Pollard_Rho(LL n,LL c){
	LL x=rand()%(n-2)+1,y=x,d;
	for(int i=1,j=2;;i++){
		x=(qmul(x,x,n)+c)%n;
		if((d=gcd(x-y+n,n))!=1)return d;
		if(y==x)return n;
		if(i==j)y=x,j<<=1;
	}
}
void Res(LL x,LL c){
	if(x<maxn){
		while(x>1)a[si++]=pre[x],x/=pre[x];
		return;
	}
	if(Miller_Rabin(x)){a[si++]=x;return;}
	LL p=x;
	while(p>=x)p=Pollard_Rho(p,c++);
	Res(p,c),Res(x/p,c);
}
LL CRT(LL a[],LL m[],LL n){//求解同余方程组 
    LL M=1,_Mi,Mi,ans=0;//_Mi为Mi的乘法逆元(%m[i]意义下的) 
    for(int i=0;i<n;i++)M*=m[i];
    for(int i=0;i<n;i++){
        Mi=M/m[i];
        _Mi=qpow(Mi,m[i]-2,m[i]);
        ans=(ans+qmul(Mi,qmul(_Mi,a[i],M),M))%M;
    }
    if(ans<0)ans+=M;
    return ans;//返回最小正整数解 
}
void work(){
	if(k>2*n){puts("0");return;}
	n<<=1,si=0;
	Res(p,1ll*rand()*rand()%p);
	for(int i=0;i<si;i++){
		LL x=n,y=n-k,z=k,w=0;
		while(x)w+=(x/=a[i]);
		while(y)w-=(y/=a[i]);
		while(z)w-=(z/=a[i]);
		if(w){b[i]=0;continue;} 
		for(int j=1;j<=n;j++){
			w=j;
			while(w%a[i]==0)w/=a[i];
			fac[j]=qmul(fac[j-1],w,a[i]);
		}
		b[i]=qmul(fac[n],qmul(qpow(fac[n-k],a[i]-2,a[i]),qpow(fac[k],a[i]-2,a[i]),a[i]),a[i]);
	}
	printf("%lld\n",CRT(b,a,si));
}
int main(){
	fac[0]=fac[1]=1;
	prime();srand(time(NULL));
	while(~scanf("%lld%lld%lld",&n,&k,&p))work();
	return 0;
} 
/*
100000 123 8921432131257
*/
