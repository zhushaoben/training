#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
int l1[maxn],l2[maxn],r1[maxn],r2[maxn];
int main(){
	int n,ans=0;scanf("%d",&n);
	r1[0]=1e9;r2[n+1]=1e9;
	for(int i=1;i<=n;i++){
		scanf("%d%d",l1+i,r1+i),l2[i]=l1[i],r2[i]=r1[i];
		l1[i]=max(l1[i-1],l1[i]),r1[i]=min(r1[i-1],r1[i]);
	}
	for(int i=n;i;i--){
		l2[i]=max(l2[i+1],l2[i]),r2[i]=min(r2[i+1],r2[i]);
		ans=max(ans,min(r2[i+1],r1[i-1])-max(l2[i+1],l1[i-1]));
	}
	printf("%d",ans);
	return 0;
}
