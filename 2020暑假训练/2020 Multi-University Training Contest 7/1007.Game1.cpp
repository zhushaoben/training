#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
typedef long long LL;
struct Node{
	int x,y;
}a[N];
struct Edge{
	LL w;int u,v,w1,k;
	bool operator < (const Edge &b)const{return w<b.w;}
}x;
LL dis(Node a,Node b){return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);}
vector<Edge>v[N];
int la[N],W[N];
priority_queue<Edge>q;
void work(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),W[i]=0,v[i].clear();
	for(int i=1;i<=n;i++){
		LL w;
		for(int j=i+1;j<=n;j++)w=dis(a[i],a[j]),v[i].push_back(Edge{w,i,j,0,0}),v[j].push_back(Edge{w,j,i,0,0});
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<n-1;j++)v[i][j].k=j;
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)q.push(v[i][la[i]=n-2]);
	int ans=0;
	while(!q.empty()){
		x=q.top();q.pop();
		int u=x.u,V=x.v,w=0;
		if(W[u])continue;
		if(W[V])w|=W[V];
		else for(int &i=la[V];v[V][i].w>x.w;i--)w|=(W[V]|=v[V][i].w1);
		v[u][x.k].w1=!w;
		if(x.k)q.push(v[u][x.k-1]);
		if(u==1)ans|=!w;
	}
	if(ans)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
