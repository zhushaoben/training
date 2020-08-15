#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7,N=2e5+5;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
void Inverse(int p,int a[],int n){
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int w[N];
void work(){
	int n,x,inv;scanf("%d",&n);
	inv=qpow(1ll*n*(n+1)/2%mo,mo-2);
	long long w1=0,w2,ans=0;
	for(int i=1;i<=n;i++)(w1+=w[i])%=mo;
	w2=w1;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		(ans+=x*w2%mo)%=mo;
		(w1-=w[i]+w[n-i+1])%=mo;
		(w2+=w1)%=mo;
	}
	printf("%d\n",(ans+mo)%mo*inv%mo);
}
int main(){
	Inverse(mo,w,N-1);
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
