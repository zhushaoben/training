#include<bits/stdc++.h>
using namespace std;
#define mo 998244353
#define LL long long
#define maxn 200005
LL Pow(LL a,int b){
	LL ans=1;
	while(b){
		if(b&1)(ans*=a)%=mo;
		(a*=a)%=mo,b>>=1;
	}
	return ans;
}
int fac[maxn],inv[maxn];
LL C(int n,int m){
	return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int main(){
	int n,k,fi,pre,x,num=0;scanf("%d%d%d",&n,&k,&fi),pre=fi;
	if(k==1)return puts("0"),0;
	for(int i=1;i<n;i++,pre=x){
		scanf("%d",&x);
		if(x!=pre)num++;
	}
	if(fi!=pre)num++;
	fac[0]=1;
	for(int i=1;i<=num;i++)fac[i]=1ll*fac[i-1]*i%mo;
	inv[num]=Pow(fac[num],mo-2);
	for(int i=num-1;~i;i--)inv[i]=1ll*inv[i+1]*(i+1)%mo;
	LL ans=Pow(k,num)-Pow(k-2,num);
	for(int i=1;i<=num/2;i++)
	(ans-=C(num,i)*C(num-i,i)%mo*Pow(k-2,num-2*i)%mo)%=mo;
	ans=(ans+mo)*Pow(2,mo-2)%mo*Pow(k,n-num)%mo;
	printf("%lld",ans);
	return 0;
}
