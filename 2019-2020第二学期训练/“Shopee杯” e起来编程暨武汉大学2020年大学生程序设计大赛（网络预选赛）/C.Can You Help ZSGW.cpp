#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
priority_queue<int>q;
int d[N],Stack[N],fa[N],ans[N];
void work(){
	int n,x=0,y;scanf("%d",&n);
	memset(d,0,sizeof(int)*(n+5));
	for(int i=1;i<=n;i++){
		scanf("%d",&y);if(y==-1)y=x+1;
		if(x>=y)fa[Stack[y]]=i,x=y-1;
		fa[i]=Stack[x],Stack[++x]=i;
	}
	for(int i=1;i<=n;i++)if(fa[i])d[fa[i]]++;
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	x=n;
	while(!q.empty()){
		int u=q.top();q.pop();
		ans[u]=x--;
		if(!(--d[fa[u]]))q.push(fa[u]);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
