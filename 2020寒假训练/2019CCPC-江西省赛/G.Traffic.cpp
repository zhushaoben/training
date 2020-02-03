#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
bool vis[maxn];
int a[maxn],b[maxn],n,m;
void work(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int j=0;j<m;j++){
		scanf("%d",b+j);
		for(int i=0;i<n;i++)if(a[i]>=b[j])vis[a[i]-b[j]]=1;
	}
	for(int i=0;;i++)if(!vis[i]){printf("%d\n",i);return;}
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
} 
