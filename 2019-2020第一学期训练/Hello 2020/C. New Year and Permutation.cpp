#include<bits/stdc++.h>
using namespace std;
#define maxn 250005
int fac[maxn];
void work(){
	int n,m;scanf("%d%d",&n,&m);
	fac[0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%m;
	for(int i=1;i<=n;i++){
		ans+=1ll*fac[i]*fac[n-i]%m*(n-i+1)%m*(n-i+1)%m;
	}
	printf("%lld\n",ans%m);
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
}
