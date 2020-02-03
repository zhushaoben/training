#include<bits/stdc++.h>
using namespace std;
int f[2005],a[1005];
int main(){
	int n,r,ans=1e9;scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);f[i]=1e9;
		if(a[i])for(int j=max(0,i-r*2+1);j<i;j++){
			if(j||(i<=r))f[i]=min(f[i],f[j]+1);
		}
	}
	for(int i=max(1,n-r+1);i<=n;i++)ans=min(ans,f[i]);
	printf("%d",ans==1e9?-1:ans);
	return 0;
}
