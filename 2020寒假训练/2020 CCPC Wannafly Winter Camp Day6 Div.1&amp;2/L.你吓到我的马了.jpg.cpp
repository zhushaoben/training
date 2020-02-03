#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char s[maxn][maxn];
int dis[maxn][maxn],que[maxn*maxn],dr[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}},S,T,n,m;
void bfs(int sx,int sy){
	dis[sx][sy]=1;que[T++]=sx*100+sy;
	while(S<T){
		int x=que[S]/100,y=que[S++]%100;
		for(int i=0;i<8;i++){
			int x1=x+dr[i][0],y1=y+dr[i][1],x2=x1+(x1>x?-1:1),y2=y1+(y1>y?-1:1);
			if(x<0||y<0||x>=n||y>=m||s[x1][y1]!='.'||s[x2][y2]=='X'||dis[x1][y1])continue;
			dis[x1][y1]=dis[x][y]+1;que[T++]=x1*100+y1;
		}
	}
}
int main(){
	int S;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++)if(s[i][j]=='M')S=i*100+j;
	}
	bfs(S/100,S%100);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)printf("%d ",dis[i][j]-1);
		puts("");
	}
	return 0;
}
