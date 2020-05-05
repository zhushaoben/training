#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=1e5+5;
void Inverse(int a[],int n){
	a[0]=a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=1ll*(mo-mo/i)*a[mo%i]%mo;
	}
}
int inv[N*2];
void work(){
	int n;scanf("%d",&n);
	Inverse(inv,n*2);
//	for(int i=1;i<=n;i++)inv[i]=1ll*inv[i]*inv[i-1]%mo;
	long long ans=1,w=1,w1=1;
	for(int i=1;i<=n;i++){
		(w*=1ll*(n-i+1)*(n+i)%mo*inv[2*i-1]%mo*inv[2*i]%mo)%=mo;
		(w1*=1ll*(4*i-2)*inv[i+1]%mo)%=mo;
		(ans+=w*w1%mo)%=mo;
	}
	printf("%d",ans);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
