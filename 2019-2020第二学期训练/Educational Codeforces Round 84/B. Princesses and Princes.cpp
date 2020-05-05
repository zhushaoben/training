#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
void work(){
	int n,k,x,ans=0;scanf("%d",&n);
	memset(vis,0,sizeof(bool)*(n+5));
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		bool fl=1;
		for(int j=0;j<k;j++){
			scanf("%d",&x);
			if(!vis[x]&&fl)vis[x]=1,fl=0;
		}
		if(fl)ans=i+1;
	}
	if(!ans){puts("OPTIMAL");return;}
	printf("IMPROVE\n%d ",ans);
	for(int i=1;i<=n;i++)if(!vis[i]){printf("%d\n",i);return;}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
