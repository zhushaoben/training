#include<bits/stdc++.h>
using namespace std;
const int N=25;
char s[N+5][N+5],op;
int dr[4][2]={{1,0},{0,1},{1,1},{1,-1}};
int main(){
	int a=0,b=0,ans=0;
	for(int i=0;i<N;i++)scanf("%s",s[i]);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)a+=(s[i][j]=='x'),b+=(s[i][j]=='o');
	if(b<a)op='o';else op='x';
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(s[i][j]!='.')continue;
			for(int k=0;k<4;k++){
				int w=1,x=i-dr[k][0],y=j-dr[k][1];
				while(x>=0&&x<N&&y>=0&&y<N&&s[x][y]==op)x-=dr[k][0],y-=dr[k][1],w++;
				x=i+dr[k][0],y=j+dr[k][1];
				while(x>=0&&x<N&&y>=0&&y<N&&s[x][y]==op)x+=dr[k][0],y+=dr[k][1],w++;
				if(w>=5){printf("%d %d\n",i,j),ans++;break;}
			}
		}
	}
	if(!ans)puts("tie");
	return 0;
} 
