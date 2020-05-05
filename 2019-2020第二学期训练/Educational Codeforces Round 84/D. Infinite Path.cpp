#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N],c[N];
bool vis[N];
void work(){
	int n;scanf("%d",&n);memset(vis,0,sizeof(bool)*(n+5));
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	int ans=1e9;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		int x=i,w=1,fl=1;
		while(p[x]!=i){
			x=p[x],w++;
			if(c[x]!=c[i])fl=0;
		}
		if(fl){puts("1");return;}
		ans=min(ans,w);
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
