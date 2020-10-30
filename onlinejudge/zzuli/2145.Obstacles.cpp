#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=4005;
const LL inf=1e18;
LL dis[N],ans;
int xl[N],xr[N],yl[N],yr[N],w[N];
priority_queue<pair<LL,int> >q;
bool check(int i,int j){
	int w=0;
	w+=(xr[i]<xl[j]-1);
	w+=(yr[i]<yl[j]-1);
	swap(i,j);
	w+=(xr[i]<xl[j]-1);
	w+=(yr[i]<yl[j]-1);
	return !w;
}
void work(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	while(!q.empty())q.pop();
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d%d",xl+i,xr+i,yl+i,yr+i,w+i);
		if(xr[i]==n||yl[i]==1)dis[i]=w[i],q.push(make_pair(-dis[i],i));
	}
	ans=1e18;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(yr[u]==m||xl[u]==1)ans=min(ans,dis[u]);
		for(int i=1;i<=k;i++)
			if((!dis[i]||dis[i]>dis[u]+w[i])&&check(i,u))dis[i]=dis[u]+w[i],q.push(make_pair(-dis[i],i));
	}
	printf("%lld\n",ans>1e15?-1:ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
/*
2
5 6 4
2 5 1 2 2000000000
1 4 4 6 1000000000
2 2 3 3 1000000000
3 3 3 3 1000000000
10000 10000 1
100 100 100 100 1
*/ 
