#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define mo 1000000007
int c[maxn],f[maxn],Pow[maxn];
int main(){
	int n,ans=0;scanf("%d",&n);
	Pow[0]=1;for(int i=0;i<n;i++)scanf("%d",c+i),Pow[i+1]=Pow[i]*2%mo,f[i+1]=(f[i]*4ll+2ll*Pow[i]*Pow[i])%mo;
	sort(c,c+n);
	for(int i=0;i<n;i++){
		(ans+=2ll*c[i]*(f[n-i-1]+1ll*Pow[n-i-1]*Pow[n-i-1]%mo)%mo*Pow[i]%mo*Pow[i]%mo)%=mo;
	}
	printf("%d",ans);
	return 0;
}
