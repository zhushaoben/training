#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int a[maxn*2+5],b[maxn+5],ans[maxn*2+5],n,k;
inline int lowbit(int x){
	return x&(-x);
}
void add(int x){
	while(x<=n)b[x]++,x+=lowbit(x);
}
int sum(int x){
	int ans=0;
	while(x)ans+=b[x],x-=lowbit(x);
	return ans;
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]++;
	int ans1=n-k+1,mx=0,x;bool fl=0;
	for(int i=1;i<=k;i++)add(a[i]),ans[i]=sum(a[i]),ans[i+k]=sum(a[i+k]),mx=(a[i]>a[i-1]?mx+1:1);
	if(mx>=k)fl=1;
	for(int i=k+1;i<=n;i++){
		add(a[i]);x=sum(a[i]);ans[i+k]=sum(a[i+k]);
		mx=(a[i]>a[i-1]?mx+1:1);
		if(mx>=k){
			if(fl)ans1--;
			else fl=1;
		}
		else if(ans[i-k]==sum(a[i-k])&&ans[i]+k==x)ans1--;
		ans[i]=x;
	}
	printf("%d",ans1);
	return 0;
}
