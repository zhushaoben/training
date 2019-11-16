#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int f[maxn+5],a[maxn+5];
int main(){
	int k1,k2,k3,x,n;scanf("%d%d%d",&k1,&k2,&k3),n=k1+k2+k3;
	for(int i=0;i<k1;i++)scanf("%d",&x),a[x]=1;
	for(int i=0;i<k2;i++)scanf("%d",&x),a[x]=2;
	for(int i=0;i<k3;i++)scanf("%d",&x),a[x]=3;
	int ans=f[0]=n-k3;
	for(int i=1;i<=n;i++){
		if(a[i]==1)f[i]=f[i-1];
		else if(a[i]==2)f[i]=f[i-1]-1;
		else f[i]=f[i-1]+1;
		ans=min(ans,f[i]=min(f[i],))
	}
	printf("%d",ans);
	return 0;
}
