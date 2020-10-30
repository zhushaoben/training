#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
int si[N],up[N];
void work(){
	int n,m,u;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)si[i]=0,up[i]=1;up[1]=0;
	for(int i=n;i;i--)si[i>>1]+=(++si[i]);
	LL ans=1ll*n*(n-1)/2;
	for(int i=0;i<m;i++){
		scanf("%d",&u);
		if(up[u]){
			up[u]=0;
			int a=si[u];
			do{
				u>>=1;
				si[u]-=a;
			}while(up[u]);
			ans-=1ll*a*si[u];
		}
		else{
			up[u]=1;
			int a=si[u];
			while(up[u])u>>=1,si[u]+=a;
			ans+=1ll*a*(si[u]-a);
		}
		printf("%lld\n",ans);
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
