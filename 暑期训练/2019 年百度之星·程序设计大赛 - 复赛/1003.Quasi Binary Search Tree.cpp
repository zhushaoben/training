#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define mo 1000000007
int l[maxn],r[maxn],T,vis[maxn],mi[maxn],p[maxn],si[maxn],m[maxn];
void dfs(int x){
	mi[x]=x;si[x]=1;
	if(l[x])dfs(l[x]),mi[x]=min(mi[x],mi[l[x]]),si[x]+=si[l[x]];
	if(r[x])dfs(r[x]),mi[x]=min(mi[x],mi[r[x]]),si[x]+=si[r[x]];
}
void dfs1(int x,int L,int R){
	if(L==R){p[x]=L;return;}
	if(!r[x]){
		if(mi[l[x]]<x)dfs1(l[x],L,R-1),p[x]=R;
		else dfs1(l[x],L+1,R),p[x]=L;
		return;
	}
	if(!l[x]){
		if(mi[r[x]]<x)dfs1(r[x],L,R-1),p[x]=R;
		else dfs1(r[x],L+1,R),p[x]=L;
		return;
	}
	if(mi[x]==x&&si[l[x]]!=si[r[x]]){
		if(si[l[x]]<si[r[x]]){
			p[x]=L+si[l[x]];
			dfs1(l[x],L,p[x]-1),dfs1(r[x],p[x]+1,R);
		}
		else{
			p[x]=L+si[r[x]];
			dfs1(r[x],L,p[x]-1),dfs1(l[x],p[x]+1,R);
		}
		return;
	}
	if(mi[l[x]]<mi[r[x]]){
		p[x]=L+si[l[x]];
		dfs1(l[x],L,p[x]-1),dfs1(r[x],p[x]+1,R);
	}
	else{
		p[x]=L+si[r[x]];
		dfs1(r[x],L,p[x]-1),dfs1(l[x],p[x]+1,R);
	}
}
void work(){
	int n,s;scanf("%d",&n);T++;
	for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i),vis[l[i]]=T,vis[r[i]]=T;
	for(int i=1;i<=n;i++)if(vis[i]!=T){s=i;break;}
	dfs(s);
	dfs1(s,1,n);
	long long ans=0;
	for(int i=1;i<=n;i++)(ans+=1ll*(p[i]^i)*m[i])%=mo;
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	m[0]=1;
	for(int i=1;i<=100000;i++)m[i]=1ll*m[i-1]*233%mo;
	while(t--)work();
	return 0;
}
