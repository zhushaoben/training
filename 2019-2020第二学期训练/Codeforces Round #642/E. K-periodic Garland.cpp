#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int f[N],sum[N];
void work(){
	int n,k;scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;s[i];i++)sum[i]=sum[i-1]+s[i]-'0';
	int ans=sum[n];
	for(int i=1;i<=k;i++)f[i]=sum[i-1]+(s[i]=='0'),ans=min(ans,f[i]+sum[n]-sum[i]);
	for(int i=k+1;i<=n;i++)f[i]=min(sum[i-1],f[i-k]+sum[i-1]-sum[i-k])+(s[i]=='0'),ans=min(ans,f[i]+sum[n]-sum[i]);
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
