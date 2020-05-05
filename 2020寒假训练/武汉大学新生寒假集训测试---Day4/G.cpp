#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,L,l,r,a,now=0,ans=0;scanf("%d%d%d",&n,&L,&a);
	for(int i=0;i<n;i++){
		scanf("%d%d",&l,&r);
		ans+=(l-now)/a,now=l+r;
	}
	ans+=(L-now)/a;
	printf("%d",ans);
	return 0;
}
