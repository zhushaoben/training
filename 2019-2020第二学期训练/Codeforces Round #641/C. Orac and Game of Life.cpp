#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int que[N*N],S,t,d[4][2]={{-1,0},{1,0},{0,1},{0,-1}},dis[N][N];
char s[N][N];
bool vis[N*N];
int main(){
	int n,m,T;scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			dis[i][j]=-1;
			for(int k=0;k<4;k++)if(s[i][j]==s[i+d[k][0]][j+d[k][1]]){que[t++]=i*m+(j-1),dis[i][j]=0;break;}
		}
	while(S<t){
		int x=que[S]/m,y=que[S]%m+1,x1,y1;vis[que[S++]]=1;
		for(int i=0;i<4;i++){
			x1=x+d[i][0],y1=y+d[i][1];
			if(x1<1||x1>n||y1<1||y1>m||dis[x1][y1]!=-1)continue;
			dis[x1][y1]=dis[x][y]+1;que[t++]=x1*m+y1-1;
		}
	}
	long long p;int x,y; 
	for(int i=0;i<T;i++){
		scanf("%d%d%lld",&x,&y,&p);
		if(dis[x][y]==-1||p<=dis[x][y]||(p-dis[x][y])%2==0){printf("%c\n",s[x][y]);continue;}
		printf("%c\n",s[x][y]^1);
	}
	return 0;
}
