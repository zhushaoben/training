#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
#define N 10000
#define LL long long
int n,a[maxn],num[maxn*5];
int c[10005];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int num){
    while(x<=N){
        c[x]+=num;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void work(){
	LL ans=0;memset(num,0,sizeof(num));
	for(int i=0;i<n;i++)scanf("%d",a+i),num[a[i]]++;
	sort(a,a+n);
	for(int i=1;i<=N;i++)if(num[i]>=2)add(N-i+1,1);
	for(int i=0;i<n;i++){
		if(i&&a[i]==a[i-1])continue;
		for(int j=i+1;j<n;j++){
			if(a[j]==a[j-1]||gcd(a[i],a[j])!=1)continue;
			if(num[a[i]]==2)add(N-a[i]+1,-1);
			if(num[a[j]]==2)add(N-a[j]+1,-1);
			ans+=sum(max(1,N-(a[j]-a[i])/2+1));
			if(num[a[i]]==2)add(N-a[i]+1,1);
			if(num[a[j]]==2)add(N-a[j]+1,1);
		}
	}
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		if(i&&a[i]==a[i-1])continue;
		for(int j=0;j<n;j++){
			if((j&&a[j]==a[j-1])||a[j]<=a[i]||gcd(a[i],a[j])==1)continue;
			add(a[j],1);
		}
		for(int j=0;j<n;j++){
			if((j&&a[j]==a[j-1])||num[a[j]]<2||gcd(a[i],a[j])!=1)continue;
			ans+=sum(min(N,a[j]*2)+a[i]);
		}
		for(int j=0;j<n;j++){
			if((j&&a[j]==a[j-1])||a[j]<=a[i]||gcd(a[i],a[j])==1)continue;
			add(a[j],-1);
		}
	}
	for(int i=0;i<n;i++){
		if(i&&a[i]==a[i-1])continue;
		for(int j=0;j<n;j++){
			if((j&&a[j]==a[j-1])||a[j]>=a[i]||gcd(a[i],a[j])==1)continue;
			add(a[j],1);
		}
		for(int j=0;j<n;j++){
			if((j&&a[j]==a[j-1])||num[a[j]]<2||gcd(a[i],a[j])!=1)continue;
			ans+=sum(min(N,a[j]*2)+a[i]);
		}
		for(int j=0;j<n;j++){
			if((j&&a[j]==a[j-1])||a[j]>=a[i]||gcd(a[i],a[j])==1)continue;
			add(a[j],-1);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
