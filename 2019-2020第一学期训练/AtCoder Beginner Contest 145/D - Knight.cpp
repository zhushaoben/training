#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define maxn 1000000
#define LL long long
LL fac[maxn+5],inv[maxn+5];
LL C(int n,int m){
	return fac[n]*inv[m]%mo*inv[n-m]%mo;
}
void Pre(int p,LL a[],int n){
    a[0]=fac[1]=a[1]=1;
    for(int i=2;i<=n;i++){
    	fac[i]=1ll*fac[i-1]*i%p;
        a[i]=1ll*(p-p/i)*a[p%i]%p;
    }
    for(int i=2;i<=n;i++)a[i]=a[i]*a[i-1]%p;
}
int main(){
	Pre(mo,inv,maxn);
	int x,y;scanf("%d%d",&x,&y);
	if((x+y)%3)return puts("0"),0;
	if(y>2*x||x>2*y)return puts("0"),0;
	int t=(x+y)/3;
	x-=t,y-=t;;
	printf("%lld",C(x+y,x));
	return 0;
}
