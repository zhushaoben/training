#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void work(){
	int n,x=0,ans=0,pre=0,mi=1e9;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x&1){
			if(pre)ans+=x+pre,pre=0;
			else pre=x;
			mi=min(x,mi);
		}
		else ans+=x;
	}
	if(pre)ans+=pre-mi;
	printf("%d\n",ans);
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
