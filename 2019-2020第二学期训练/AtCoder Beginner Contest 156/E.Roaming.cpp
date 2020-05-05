#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7,N=2e5+5;
typedef long long LL;
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(p-p/i)*a[p%i]%p;
	}
}
int inv[N];
int main(){
	int n,k;scanf("%d%d",&n,&k),k=min(k,n-1);
	Inverse(mo,inv,n-1);
	LL ans=(k!=1),a=1,b=1;
	for(int i=1;i<=k;i++){
		a=a*inv[i]%mo*(n-i+1)%mo,b=b*inv[i]%mo*(n-i)%mo;
		(ans+=a*b)%=mo;
	}
	printf("%d",ans);
	return 0;
}
