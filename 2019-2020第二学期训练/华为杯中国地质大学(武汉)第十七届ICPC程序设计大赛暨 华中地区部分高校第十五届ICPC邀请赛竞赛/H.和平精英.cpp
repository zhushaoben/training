#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double eps=1e-7;
long double dis(int x,int y,int x1,int y1){
	return sqrt((long double)(x-x1)*(x-x1)+(long double)(y-y1)*(y-y1));
}
int a[200],b[200],que[200],s,t,X,Y,n;
bool vis[200];
bool check(double x){
	s=t=0;memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)if(a[i]<x)que[t++]=i,vis[i]=1;
	while(s<t){
		int u=que[s++];
		if(X-a[u]<x||b[u]<x)return 1;
		for(int i=0;i<n;i++){
			if(!vis[i]&&dis(a[i],b[i],a[u],b[u])<x*2)que[t++]=i,vis[i]=1;
		}
	}
	s=t=0;memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)if(X-a[i]<x)que[t++]=i,vis[i]=1;
	while(s<t){
		int u=que[s++];
		if(Y-b[u]<x)return 1;
		for(int i=0;i<n;i++){
			if(!vis[i]&&dis(a[i],b[i],a[u],b[u])<x*2)que[t++]=i,vis[i]=1;
		}
	}
	s=t=0;memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)if(b[i]<x)que[t++]=i,vis[i]=1;
	while(s<t){
		int u=que[s++];
		if(Y-b[u]<x)return 1;
		for(int i=0;i<n;i++){
			if(!vis[i]&&dis(a[i],b[i],a[u],b[u])<x*2)que[t++]=i,vis[i]=1;
		}
	}
	return 0;
}
void work(){
	scanf("%d%d%d",&n,&X,&Y);
	for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
	double l=0,r=1e10,mid;
	while(r-l>eps){
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.3lf",mid);
}
int main(){
	int t=1;
//	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
