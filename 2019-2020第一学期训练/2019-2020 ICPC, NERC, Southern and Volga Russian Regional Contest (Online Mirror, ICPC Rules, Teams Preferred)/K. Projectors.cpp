#include<bits/stdc++.h>
using namespace std;
#define maxn 300
int n,m,x,y;
struct Node{
	int l,r,ans;
}a[maxn*2+5],b[maxn+5];
struct Edge{
	int next,to,fl;
}edge[maxn*11];
int w[maxn*5],si,num[maxn*5],num1[maxn*5],fi[maxn*5],se;
inline void add_edge(int u,int v,int fl){edge[++se].next=fi[u],fi[u]=se,edge[se].to=v,edge[se].fl=fl;}
inline void add(int u,int v,int fl){add_edge(u,v,fl),add_edge(v,u,0);}
void read(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	memset(num,0,sizeof(num)),memset(num1,0,sizeof(num1));
	num[0]=x,num1[0]=y;si=0;
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].l,&a[i].r),w[si++]=a[i].l,w[si++]=a[i].r,a[i].ans=0;
	for(int i=0;i<m;i++)scanf("%d%d",&b[i].l,&b[i].r),w[si++]=b[i].l,w[si++]=b[i].r;
	sort(w,w+si),si=unique(w,w+si)-w;
	for(int i=0;i<n;i++){
		a[i].l=lower_bound(w,w+si,a[i].l)-w+1,a[i].r=lower_bound(w,w+si,a[i].r)-w+1;
		num[a[i].l]--,num[a[i].r]++;
	}for(int i=0;i<m;i++){
		b[i].l=lower_bound(w,w+si,b[i].l)-w+1,b[i].r=lower_bound(w,w+si,b[i].r)-w+1;
		num1[b[i].l]--,num1[b[i].r]++;
	}
}
int build(){
	memset(fi,0,sizeof(fi)),se=1;
	for(int i=0;i<m;i++)add(b[i].l,b[i].r,1);
	for(int i=1;i<=si;i++){
		num[i]+=num[i-1],num1[i]+=num1[i-1],add(i,i+1,min(y,num[i]+num1[i]));
		if(num[i]<0||num[i]+num1[i]<0)return 1;
	}
	return 0;
}
int s,t,inf=0x1fffffff,que[maxn*5],S,T,dis[maxn*5],cur[maxn*5];
bool bfs(){
	S=T=0;memset(dis,0,sizeof(dis));
	que[T++]=s;dis[s]=1;
	for(int i=1;i<=t;i++)cur[i]=fi[i];
	while(S<T){
		int u=que[S++];
		for(int i=fi[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].fl&&!dis[v])dis[v]=dis[u]+1,que[T++]=v;
		}
	}
	return dis[t];
}
int dfs(int x,int w){
	if(x==t||!w)return w;
	int flow=0,w1;
	for(int &i=cur[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(dis[v]!=dis[x]+1||!edge[i].fl)continue;
		w1=dfs(v,min(w,edge[i].fl));
		edge[i].fl-=w1,edge[i^1].fl+=w1,flow+=w1;
	}
	return flow;
}
int dinic(){
	int ans=0;
	while(bfs())
		ans+=dfs(s,inf);
	return ans;
}
vector<int>t1[maxn*5],t2[maxn*5];
queue<int>A,B;
int work(){
	read();s=1,t=si+1;
	if(build())return puts("NO"),0;
	if(dinic()<y)return puts("NO"),0;
	for(int i=0;i<m;i++)b[i].ans=!(edge[(i+1)<<1].fl);
	for(int i=0;i<m;i++)a[n++]=b[i];
	for(int i=1;i<=si;i++)t1[i].clear(),t2[i].clear();
	for(int i=0;i<n;i++)t1[a[i].l].push_back(i),t2[a[i].r].push_back(i);
	while(!A.empty())A.pop();while(!B.empty())B.pop();
	for(int i=1;i<=x;i++)A.push(i);for(int i=1;i<=y;i++)B.push(i+x);
	for(int i=1;i<=si;i++){
		for(auto j:t2[i]){
			if(a[j].ans>x)B.push(a[j].ans);
			else A.push(a[j].ans);
		}
		for(auto j:t1[i]){
			if(a[j].ans){a[j].ans=B.front();B.pop();}
			else{a[j].ans=A.front();A.pop();}
		}
	}
	for(int i=(puts("YES"),0);i<n;i++)printf("%d ",a[i].ans);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
