#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char s[maxn][maxn];
int a[maxn][maxn],b[maxn][maxn],ans1,ans2,dr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void work(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	ans1=ans2=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='g'){a[i][j]=0;continue;}
		a[i][j]=1;
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='i')continue;
		for(int k=0;k<4;k++){
			int x=i+dr[k][0],y=j+dr[k][1];
			if(x<0||x>=n||y<0||y>=m||s[x][y]!='g')continue;
			a[i][j]+=a[x][y];
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='r')continue;
		for(int k=0;k<4;k++){
			int x=i+dr[k][0],y=j+dr[k][1];
			if(x<0||x>=n||y<0||y>=m||s[x][y]!='i')continue;
			a[i][j]+=a[x][y];
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='l')continue;
		for(int k=0;k<4;k++){
			int x=i+dr[k][0],y=j+dr[k][1];
			if(x<0||x>=n||y<0||y>=m||s[x][y]!='r')continue;
			a[i][j]+=a[x][y];
		}
		ans1+=a[i][j];
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='c'){b[i][j]=0;continue;}
		b[i][j]=1;
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='a')continue;
		for(int k=0;k<4;k++){
			int x=i+dr[k][0],y=j+dr[k][1];
			if(x<0||x>=n||y<0||y>=m||s[x][y]!='c')continue;
			b[i][j]+=b[x][y];
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]!='t')continue;
		for(int k=0;k<4;k++){
			int x=i+dr[k][0],y=j+dr[k][1];
			if(x<0||x>=n||y<0||y>=m||s[x][y]!='a')continue;
			b[i][j]+=b[x][y];
		}
		ans2+=b[i][j];
	}
	printf("%d %d\n",ans1,ans2);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
