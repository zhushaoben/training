#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
char s[maxn][maxn];
int f[maxn][maxn];
void update(int x1,int y1,int x2,int y2){
	f[x1][y1]++;f[x1][y2+1]--;
	f[x2+1][y1]--;f[x2+1][y2+1]++;
}
int main(){
	int n,k,ans=0,w=0;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		int l=n+1,r=0,u=max(1,i-k+1),d=i;
		for(int j=1;j<=n;j++){
			if(s[i][j]=='B')l=min(l,j),r=j;
		}
		if(!r){ans++;continue;}
		int l1=l;
		l=max(1,r-k+1),r=l1;
		if(r>=l)update(l,u,r,d);
	}
	for(int i=1;i<=n;i++){
		int l=max(1,i-k+1),r=i,u=n+1,d=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='B')u=min(u,j),d=j;
		}
		if(!d){ans++;continue;}
		int u1=u;
		u=max(1,d-k+1);d=u1;
		if(d>=u)update(l,u,r,d);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]+=f[i-1][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]+=f[i][j-1];
			w=max(w,f[i][j]);
		}
	}
	printf("%d\n",ans+w);
	return 0;
}
