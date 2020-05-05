#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int num[maxn],n,k;
bool check(int x){
	int sum=0;
	for(int i=1;i<=2e5;i++){
		sum+=num[i]/x;
	}
	return sum>=k;
}
int main(){
	int x;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x),num[x]++;
	}
	int l=1,r=n/k,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	int ans=k,w;
	for(int i=1;i<=2e5;i++){
		w=min(ans,num[i]/r),ans-=w;
		for(int j=0;j<w;j++)printf("%d ",i);
	}
	return 0;
}
