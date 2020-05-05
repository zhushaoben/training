#include<bits/stdc++.h>
using namespace std;
const int N=3005,mo=998244353;
int f[N];
int main(){
	int n,s,ans=0,x;scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=s-x;j>0;j--)(f[j+x]+=f[j])%=mo;
		(f[x]+=i)%=mo;
		(ans+=f[s])%=mo;
	}
	printf("%d",ans);
	return 0;
}
