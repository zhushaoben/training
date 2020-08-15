#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 
const int mo=998244353;
int si,a[100],inv[100],fac[100];LL que[100];
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;}
void pre(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=2;i<100;i++)inv[i]=1ll*(mo-(mo/i))*inv[mo%i]%mo;
	for(int i=1;i<100;i++)inv[i]=1ll*inv[i]*inv[i-1]%mo,fac[i]=1ll*i*fac[i-1]%mo;
}
LL calc(LL u,LL v){
	int s=0,b,c;LL ans=1;
	for(int j=0;j<si;j++){
		b=c=0;
		while(u%que[j]==0)b++,u/=que[j];
		while(v%que[j]==0)c++,v/=que[j];
		s+=(a[j]=c-b);
	}
	for(int j=0;j<si;j++)
		ans=ans*C(s,a[j])%mo,s-=a[j];
	return ans;
}
int main(){
	pre();
	LL n,u,v;int q;scanf("%lld%d",&n,&q);
	for(LL i=2;i*i<=n;i++)if(n%i==0){
		que[si++]=i;
		while(n%i==0)n/=i;
	}
	if(n>1)que[si++]=n;
	for(int i=0;i<q;i++){
		LL u,v,w;scanf("%lld%lld",&u,&v),w=gcd(u,v);
		printf("%d\n",calc(w,u)*calc(w,v)%mo);
	}
	return 0;
}
