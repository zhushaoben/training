#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,pre,x,ans=1;scanf("%d%d",&n,&pre);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		if(x!=pre+1)ans=i;
		pre=x;
	}
	printf("%d\n",ans);
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		work();
	}
	return 0;
} 
