#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int vis[N],in[N];
int main(){
	int n,x,mx=0,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),mx=max(mx,x),in[x]++;
	for(int i=1;i<=mx;i++){
		if(!in[i])continue;
		if(!vis[i]&&in[i]==1)ans++;
		for(int j=i;j<=mx;j+=i)vis[j]=1;
	}
	printf("%d",ans);
	return 0;
}
