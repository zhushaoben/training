#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int mi[maxn],ma[maxn],s[maxn*10];
bool fl[maxn];
void work(){
	int n,w,x,d=0,pre;scanf("%d",&n);
	for(int i=0;i<n;i++){
		ma[i]=0,pre=mi[i]=1e7;scanf("%d",&w);
		for(int j=0;j<w;j++){scanf("%d",&x),ma[i]=max(ma[i],x),mi[i]=min(mi[i],x);if(x>pre)fl[i]=1;pre=x;}
		if(!fl[i])s[ma[i]]++;
		else d++;
	}
	for(int i=1e6;i;i--)s[i]+=s[i+1];
	long long ans=0;
	for(int i=0;i<n;i++){
		if(!fl[i])ans+=s[mi[i]+1];
	}
	printf("%lld\n",ans+1ll*d*d+1ll*(n-d)*d*2);
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
}
