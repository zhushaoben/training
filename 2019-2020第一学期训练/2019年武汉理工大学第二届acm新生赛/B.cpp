#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[20],n;LL sum,ans;
bool check(LL x){
	LL x1=sqrt(x);
	if(x<=1)return 0;
	for(int i=2;i<=x1;i++)if(x%i==0)return 0;
	return 1;
}
void dfs(int x,int d){
	if(!d){
		if(check(sum))ans=max(ans,sum);
	}
	for(int i=x;i<n;i++){
		sum+=a[i];
		dfs(i+1,d-1);
		sum-=a[i];
	}
}
void work(){
	int m;scanf("%d%d",&n,&m);sum=0;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	dfs(0,m);
	printf("%lld\n",ans?ans:-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
