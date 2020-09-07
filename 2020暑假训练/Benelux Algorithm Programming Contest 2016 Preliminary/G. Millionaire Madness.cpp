#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N][N],que[N*N],s,t,vis[N*N],T,dr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int w){
	s=t=0;que[t++]=0;vis[0]=++T;
	while(s<t){
		int x=que[s++],y=x%m;x/=m;
		for(int i=0;i<4;i++){
			int x1=x+dr[i][0],y1=y+dr[i][1],z=x1*m+y1;
			if(x1<0||y1<0||x1>=n||y1>=m)continue;
			if(vis[z]!=T&&a[x1][y1]-a[x][y]<=w)que[t++]=z,vis[z]=T;
		}
		if(vis[n*m-1]==T)return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",a[i]+j);
	int l=0,r=1e9,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
