#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL lowbit(LL x){return x&-x;}
LL calc(LL x){
	LL ans=x,d=1;x/=2;
	while(x)ans+=x*d,x>>=1,d<<=1;
	return ans;
}
int main(){
	LL n,l,r;int op,q;
	while(~scanf("%lld%d",&n,&q)){
		for(int i=0;i<q;i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%lld%lld",&l,&r);
				printf("%lld\n",calc(r)-calc(l-1));
			}
			else{
				scanf("%lld",&l);int ans=0;
				while(l<=n)l+=lowbit(l),ans++;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
} 
