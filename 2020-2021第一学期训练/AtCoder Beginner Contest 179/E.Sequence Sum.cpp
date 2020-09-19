#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5; 
int a[N],b[N];
LL s[N];
int main(){
	LL n,ans=0;int x,m,si=0;scanf("%lld%d%d",&n,&x,&m);
	while(!b[x])b[x]=++si,a[si]=x,s[si]=s[si-1]+x,x=1ll*x*x%m;
	if(n<=b[x])return printf("%lld",s[n]),0;
	ans+=s[b[x]-1],n-=b[x]-1;
	ans+=(n/(si-b[x]+1))*(s[si]-s[b[x]-1]);
	ans+=s[b[x]+n%(si-b[x]+1)-1]-s[b[x]-1];
	printf("%lld",ans);
	return 0;
}
