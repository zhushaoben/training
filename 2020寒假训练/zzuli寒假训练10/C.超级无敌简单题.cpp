#include<bits/stdc++.h>
using namespace std;
#define maxn 150005
int ans[maxn],si=0,f[maxn*10];
int dp(int x){
	int w=0,w1,x1=x;
	if(f[x]>0)return f[x];
	if(f[x]==-1)return f[x]=1;;
	while(x1)w1=x1%10,x1/=10,w+=w1*w1;
	f[x]=-1;
	return f[x]=dp(w);
}
int main(){
	ans[++si]=1;f[1]=2;
	for(int i=2;;i++){
		if(dp(i)==2)ans[++si]=i;
		if(si==maxn-5)break;
	}
	int q,k;scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		printf("%d\n",ans[k]);
	}
	return 0;
}
