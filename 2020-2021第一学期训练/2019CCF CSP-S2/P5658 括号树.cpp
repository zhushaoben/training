#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int fa[N],match[N];LL w[N];char s[N];
int main(){
	int n;scanf("%d%s",&n,s+1);
	for(int i=2;i<=n;i++)scanf("%d",fa+i);
	for(int x=1;x<=n;x++){
		if(s[x]=='(')continue;
		int u=fa[x];
		while(u){
			if(s[u]=='('&&s[x]==')'){match[x]=u;break;}
			u=fa[match[u]];
		}
		if(u)w[x]=1+w[fa[u]];
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		w[i]+=w[fa[i]];
		ans^=i*w[i];
	}
	printf("%lld\n",ans);
	return 0;
}
