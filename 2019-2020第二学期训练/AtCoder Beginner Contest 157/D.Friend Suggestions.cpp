#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int fa[N],si[N],ans[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	int n,m,k,x,y;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i,si[i]=1;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);ans[x]++,ans[y]++;
		x=find(x),y=find(y);
		if(x!=y)fa[y]=x,si[x]+=si[y];
	}
	for(int i=0;i<k;i++){
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))ans[x]++,ans[y]++;
	}
	for(int i=1;i<=n;i++){
		int x=find(i);
		printf("%d ",si[x]-ans[i]-1);
	}
	return 0;
}
