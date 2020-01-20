#include<bits/stdc++.h>
using namespace std;
int n,m,que[1000],s,t,dr[4][2]={{0,1},{1,0},{0,-1},{-1,0}},dis[30][30];
char S[30][30];
int bfs(int st){
	s=t=0;que[t++]=st;memset(dis,0x1f,sizeof(dis));
	dis[st/20][st%20]=0;
	while(s<t){
		int x=que[s++],y=x%20;x/=20;
		for(int i=0;i<4;i++){
			int x1=x+dr[i][0],y1=y+dr[i][1];
			if(x1<0||x1>=n||y1<0||y1>=m||S[x1][y1]!='.'||dis[x1][y1]<=dis[x][y]+1)continue;
			dis[x1][y1]=dis[x][y]+1,que[t++]=x1*20+y1;
		}
	}
	return dis[que[t-1]/20][que[t-1]%20];
}
int main(){
	int ans=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",S[i]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(S[i][j]=='.')ans=max(ans,bfs(i*20+j));
	printf("%d",ans);
	return 0;
}
