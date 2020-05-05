#include<bits/stdc++.h>
using namespace std;
int s[1005][1005],dr[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void work(){
	int n,m,r,c,x=1,y=1,d=0;scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=1;;i++){
		s[x][y]=i;
		if(x==r&&c==y)break;
		int x1=x+dr[d][0],y1=y+dr[d][1];
		if(x1<1||x1>n||y1<1||y1>m||s[x1][y1])d=(d+1)%4;
		x+=dr[d][0],y+=dr[d][1];
	}
	printf("%d",s[r][c]);
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
