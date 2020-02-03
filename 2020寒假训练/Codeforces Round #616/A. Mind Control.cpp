#include<bits/stdc++.h>
using namespace std;
int a[4005];
int calc(int l,int r,int si){
	int ans=1e9;
	for(int i=l;i+si-1<=r;i++){
		ans=min(ans,max(a[i],a[i+si-1]));
	}
	return ans;
}
void work(){
	int n,m,k,ans=0;scanf("%d%d%d",&n,&m,&k),k=min(k,m-1);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<=k;i++){
		ans=max(ans,calc(i,n-k+i-1,n-m+1));
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
