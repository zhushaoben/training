#include<bits/stdc++.h>
using namespace std;
char s[1000005];
bool vis[30];int fa[200055];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void merge(int i,int j){
	i=Find(i),j=Find(j),fa[i]=j;
}
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<=n+26;i++)fa[i]=i;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		memset(vis,0,sizeof(vis));
		for(int j=0;s[j];j++)vis[s[j]-'a']=1;
		for(int j=0;j<26;j++)if(vis[j])merge(j+n,i);
	}
	int ans=0;
	for(int i=0;i<n;i++)if(fa[i]==i)ans++;
	printf("%d",ans);
}
int main(){
	int t=1;//scanf("%d",&t);
	while(t--)work();
	return 0;
} 
