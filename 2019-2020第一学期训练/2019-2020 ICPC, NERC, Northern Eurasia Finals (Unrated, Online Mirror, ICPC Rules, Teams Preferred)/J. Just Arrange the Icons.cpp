#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
int a[maxn];
bool vis[maxn];
void work(){
	int n,x,mi=maxn;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),a[x]++;
	for(int i=1;i<=n;i++)mi=min(mi,(a[i]?a[i]:maxn)+1);
	for(int i=2;i<=mi;i++)vis[i]=1;
	for(int i=1;i<=n;i++)if(a[i])for(int j=2;j<=mi;j++)if(vis[j]&&(a[i]-1)/j==a[i]/(j-1))vis[j]=0;
	int ans=0;while(!vis[mi])mi--;
	for(int i=1;i<=n;i++)if(a[i])ans+=(a[i]-1)/mi+1,a[i]=0;
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
