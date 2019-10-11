#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define maxn 2005
int a[maxn],b[maxn],c[maxn];
int main(){
	int n,k,x;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		b[x]+=a[x],c[x]++;
		for(int j=x+1;j<=2000;j++)a[j]++;
	}
	int ans=0;
	for(int x=1;x<=2000;x++){
		b[x]=a[x]*c[x]-b[x];
		a[x]=1ll*a[x]*c[x]%mo*(k-1)%mo;(a[x]+=b[x])%=mo;
		(ans+=1ll*(b[x]+a[x])*k%mo*500000004%mo)%=mo;
	}
	printf("%d\n",ans);
	return 0;
}
