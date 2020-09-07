#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%d",&t);
	int n,x;long long ans,w;
	while(t--){
		scanf("%d",&n),ans=w=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x),w+=x;
			if(w<0)ans-=w,w=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
