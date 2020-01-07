#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define mo 998244353
int k[maxn],fi[maxn],w[maxn],s,b[maxn],inv[maxn];
void Inverse(int p,int a[],int n){//线性求<=n的数%p意义下的逆元 
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=1ll*(p-p/i)*a[p%i]%p;
    }
}
int main(){
	int n;scanf("%d",&n);
	Inverse(mo,inv,1000000);
	for(int i=0;i<n;i++){
		scanf("%d",k+i);fi[i]=s;
		for(int j=0;j<k[i];j++)scanf("%d",w+s),b[w[s++]]++;
	}
	int w1,ans=0;
	for(int i=0;i<n;i++){
		w1=0;
		for(int j=0;j<k[i];j++)(w1+=b[w[j+fi[i]]])%=mo;
		(ans+=1ll*w1*inv[n]%mo*inv[n]%mo*inv[k[i]]%mo)%=mo;
	}
	printf("%d\n",ans);
	return 0;
}
