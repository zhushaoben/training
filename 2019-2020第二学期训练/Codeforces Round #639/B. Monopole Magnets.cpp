#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char s[N][N];
bool vis[N][N];
int n,m;
void dfs(int x,int y){
	if(x<0||x>=n||y<0||y>=m||vis[x][y]||s[x][y]!='#')return;
	vis[x][y]=1;
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(abs(i)+abs(j)==1)dfs(x+i,y+j);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	bool fl=1,fl1=1;
	for(int i=0;i<n;i++){
		bool w=0,w1=0;
		for(int j=0;j<m;j++){
			if(s[i][j]=='#'){
				if(w1)return puts("-1"),0;
				w=1;
			}
			else if(w)w1=1;
		}
		fl&=w;
	}
	for(int i=0;i<m;i++){
		bool w=0,w1=0;
		for(int j=0;j<n;j++){
			if(s[j][i]=='#'){
				if(w1)return puts("-1"),0;
				w=1;
			}
			else if(w)w1=1;
		}
		fl1&=w;
	}
	if(fl^fl1)return puts("-1"),0;
	int ans=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='#'&&!vis[i][j])
		dfs(i,j),ans++;
	printf("%d",ans);
	return 0;
}
