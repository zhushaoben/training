#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void work(){
	int n,m,x,ma=-1e9;LL mi=0,ans=0,sum=0,ans1=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&x);ma=max(ma,x);
		sum+=x,ans=max(ans,sum-mi);
		mi=min(mi,sum);
	}
	sum=mi=0;
	for(int i=0;i<m;i++){
		scanf("%d",&x);ma=max(ma,x);
		sum+=x;ans1=max(ans1,sum-mi);
		mi=min(mi,sum);
	}
	printf("%lld\n",ma<=0?ma:ans+ans1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
