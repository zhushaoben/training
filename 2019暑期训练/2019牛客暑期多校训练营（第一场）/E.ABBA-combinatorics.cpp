#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define maxn 4000
int a,b,fac[maxn+5],inv[maxn+5];
int C(int a,int b){
	if(b<0)return 0;
	return 1ll*fac[a]*inv[b]%mo*inv[a-b]%mo;
}
void work(){
	int n=a+b; 
	printf("%d\n",((C(n*2,n)-C(n*2,a-1)-C(n*2,b-1))%mo+mo)%mo);
}
int main(){
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2;i<=maxn;i++)fac[i]=1ll*fac[i-1]*i%mo,inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for(int i=1;i<=maxn;i++)inv[i]=1ll*inv[i-1]*inv[i]%mo; 
	while(~scanf("%d%d",&a,&b))work();
	return 0;
} 
