#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e3;
const LL inf=1e15;
LL w[N],f[N],d[N];
int main(){
	int n;scanf("%d",&n);
	LL c,f1,u,x,s=0;
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld%lld",d+i,&c,&f1,&u);
		x=(c+f1+u)/2+1-c;
		w[i]=x<=u?max(x,0ll):inf;
	}
	memset(f,0x1f,sizeof(f));f[0]=0;
	for(int i=0;i<n;i++){
		s+=d[i];
		for(int j=s;j>=d[i];j--){
			f[j]=min(f[j],f[j-d[i]]+w[i]);
		}
	}
	int t=s/2+1;LL ans=inf;
	for(int i=t;i<=s;i++)ans=min(ans,f[i]);
	if(ans==inf)puts("impossible");
	else printf("%lld\n",ans);
	return 0;
}
