#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int pre[maxn+5];
void work(){
	int n,ans=maxn*2,x;scanf("%d",&n);
	memset(pre,0,sizeof(int)*(n+10));
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(pre[x])ans=min(ans,i-pre[x]+1);
		pre[x]=i;
	}
	printf("%d\n",ans<=maxn?ans:-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
