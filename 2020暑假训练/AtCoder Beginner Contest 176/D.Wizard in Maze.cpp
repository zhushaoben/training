#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e3+5;
char S[N][N];
int f[N][N],dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}},que[N*N],s,t;
int main(){
	int h,w,sx,sy,tx,ty;scanf("%d%d%d%d%d%d",&h,&w,&sx,&sy,&tx,&ty);
	for(int i=0;i<h;i++){
		scanf("%s",S[i]);
		for(int j=0;j<w;j++)f[i][j]=S[i][j]=='#';
	}
	f[--sx][--sy]=1;tx--,ty--;
	que[t++]=sx*N+sy;
	while(s<t){
		int s1=s;
		while(s<t){
			int x=que[s++],y=x%N;x/=N;
			for(int i=0;i<4;i++){
				int x1=x+dr[i][0],y1=y+dr[i][1];
				if((unsigned)x1>=h||(unsigned)y1>=w||f[x1][y1])continue;
				f[x1][y1]=f[x][y];que[t++]=x1*N+y1;
			}
		}
		while(s1<s){
			int x=que[s1++],y=x%N;x/=N;
			for(int i=-2;i<3;i++){
				for(int j=-2;j<3;j++){
					int x1=x+i,y1=y+j;
					if((unsigned)x1>=h||(unsigned)y1>=w||f[x1][y1])continue;
					f[x1][y1]=f[x][y]+1;que[t++]=x1*N+y1;
				}
			}
		}
	}
	printf("%d",f[tx][ty]?f[tx][ty]-1:-1);
	return 0;
}
