#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mo=998244353;
vector<int>V[N];
int f[N],s[N];
int main(){
	int n,m,u,v;scanf("%*d%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&u,&v),V[u].push_back(v);
	for(int i=1;i<=n;i++){
		int d=V[i].size()+1;
		f[i]=d;
		for(auto j:V[i])
			f[i]=(1ll*f[i]+s[i-1]-s[j-1])%mo;
		s[i]=(s[i-1]+f[i])%mo;
	}
	printf("%d",(s[n]+mo)%mo);
	return 0;
} 
